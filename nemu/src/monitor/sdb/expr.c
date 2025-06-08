/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

//感觉基本完善了这个表达式求值，但中间有依赖AI的部分，不够纯粹


#include <isa.h>
/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
//根据地址取值使用的头文件
#include </home/lzy14/ysyx/ysyx-workbench/nemu/include/memory/vaddr.h>
bool check_parentheses(int p,int q);
int find_main_op(int p,int q);
word_t eval(int p,int q,bool* success);
enum {
  //空格串的token类型是TK_NOTYPE
  TK_NOTYPE = 256, 
  //相等
  TK_EQ,
  //十进制
  TK_NUM,
  //逻辑与
  TK_H,
  //不相等
  TK_UEQ,
  //指针*
  TK_PT,
  //16进制
  TK_ST,
  //寄存器
  TK_RN,
  //负号
  TK_MS
  /* TODO: Add more token types */
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */
//双斜杠（\\）是先对 C 语言字符串里的斜杠进行转义，接着该斜杠又会对正则表达式中的特殊字符进行转义。
  {" +", TK_NOTYPE},    // spaces
  {"==", TK_EQ},        // equal
  {"!=",TK_UEQ},        //不等
  {"&&",TK_H},      //逻辑与
  {"\\+", '+'},         // plus
  {"\\-", '-'},
  {"\\*", '*'},
  {"\\/", '/'},
  {"\\(", '('},
  {"\\)", ')'},
  {"0x[0-9a-fA-F]+",TK_ST},  //16
  {"[0-9]+", TK_NUM},       //10
  {"\\$[0-9a-zA-Z]+",TK_RN}    //寄存器
  
};

//数组的长度
#define NR_REGEX ARRLEN(rules)

//用于存储编译后的正则表达式
static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    //regcomp()编译正则表达式
    //第一个参数：用于储存编译后的正则表达式
    //第二个参数：正则表达式字符串
    //第三个参数：REG_EXTENDED：使用扩展正则表达式语法（默认）
    //成功返回0，失败返回错误代码，可通过regerror()转换为错误信息.
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      //判断参数是否失败
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

//Token结构体来记录token的信息
typedef struct token {
  int type;
  char str[32];
} Token;

//tokens数组用于按顺序存放已经被识别出的token信息.
static Token tokens[1024] __attribute__((used)) = {};

//nr_token指示已经被识别出的token数目.
static int nr_token __attribute__((used)) = 0;

//识别出其中的token
static bool make_token(char *e) {
  int position = 0;
  int i;

  //用于存储正则表达式匹配的位置信息.
  //regmatch_t 是一个关键结构体，专门用于记录匹配结果的起始和结束位置。
  regmatch_t pmatch;

  //nr_token指示已经被识别出的token数目.
  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i++) {
      //使用编译后的正则表达式对目标字符串进行匹配，返回匹配结果
      //1：指向已编译的正则表达式
      //2：待匹配的目标字符串
      //3:pmatch 数组的大小(即最多存储的匹配结果数)
      //4：存储匹配位置的数组
      //5：执行标记
      /*
        REG_NOTBOL：不将字符串开头视为行首（^ 可能不匹配）。
        REG_NOTEOL：不将字符串结尾视为行尾（$ 可能不匹配）。
      */
      //返回值：成功返回0，失败返回REG_NOMATCH，其他值是匹配中出现错误，可以用regerror获取错误信息

      // pmatch.rm_so：匹配子串的起始位置（从 0 开始的字节索引）
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        //rm_eo：匹配子串的结束位置的下一个字节的索引（即 rm_so + 匹配长度.
        int substr_len = pmatch.rm_eo;
        //  Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
        //      i, rules[i].regex, position, substr_len, substr_len, substr_start);
            
        //移动
        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        //记录信息的
        switch (rules[i].token_type) {
          case '+':
          case '-':
          case '*':
          case '/':
          case '(':
          case ')':
          case TK_H:
          case TK_MS:
          case TK_EQ:
          case TK_UEQ:
            //类型
            tokens[nr_token++].type = rules[i].token_type;
            break;
          //10进制
          case TK_NUM:
          //16进制
          case TK_ST:
          //寄存器的值
          case TK_RN:
          //寄存器的值
            //类型
            tokens[nr_token].type = rules[i].token_type;
            //提取数字到str中
            strncpy(tokens[nr_token].str, substr_start,substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            break;
            //如果是空格不做处理
          case TK_NOTYPE:
              
            break;
          default:
            printf("表达式有问题，请仔细核对一下");
            return false;
            break;
        }
        //对应上了直接退出，不需要继续匹配了；
        break;
      }
    }
    //匹配失败返回NR_REGEX的情况
    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}


//主逻辑
word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  if(nr_token <= 0){
    *success = false;
    return 0;
  }

  /* TODO: Implement code to evaluate the expression. */

  //区分解引用和乘法
  for (int i = 0; i < nr_token; i ++) {
    if (tokens[i].type == '*' && (i == 0 || (tokens[i - 1].type != TK_NUM && tokens[i-1].type != TK_ST)) ) {
      tokens[i].type = TK_PT;
    }
  }
  
  //区分减号和负号
  for (int i = 0; i < nr_token; i ++) {
    if (tokens[i].type == '-' && (i == 0 || (tokens[i - 1].type != TK_NUM && tokens[i-1].type != TK_ST)) ) {
      //printf("处理了减号!\n");
      tokens[i].type = TK_MS;
    }
  }


  word_t result = eval(0,nr_token-1,success);
  /* TODO: Insert codes to evaluate the expression. */
  //TODO();
  //printf("expr中的result: %u \n",result);
  return result;
}



//递归求值函数
word_t eval(int p,int q,bool *success) {
  if (p > q) {
    /* Bad expression */
    printf(" Bad expression!\n");
    *success = false;
    return 1;
  }else if (p == q) {
    /* Single token.
    * For now this token should be a number.
    * Return the value of the number.
    */
    //处理正常10进制数
    if(tokens[p].type == TK_NUM ){
      uint32_t n;
      sscanf(tokens[p].str,"%u",&n);
      return n;
    }
    //处理16进制的数
    else if(tokens[p].type == TK_ST){
      uint32_t st =strtoul(tokens[p].str,NULL,16);
      return st;
    }
    //处理寄存器的值
    else if(tokens[p].type == TK_RN){
      bool success_flag = false;
      uint32_t tem_reg = isa_reg_str2val(tokens[p].str, &success_flag);
      //处理解指针和寄存器的值
      if(success_flag){
          return tem_reg;
      }else{
        Log("寄存器名字%s取地址失败!\n",tokens[p].str);
        *success = false;
        return 0;
      }
    }else{
      //识别解引用的时候可能会出现问题
      return 0;
    }
  }else if (check_parentheses(p, q) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    //printf("消除过一次括号了\n");
    return eval(p + 1, q - 1,success);
  }else {
    int op = find_main_op(p,q);
     if(op==-1){
        Log("Error: No operator found between %d and %d\n", p, q);
         return false;
     }
     //处理解指针
     if(tokens[op].type == TK_PT){
        uint32_t addr = eval(op+1,q,success);
        uint32_t val = vaddr_read(addr,4);
        //printf("处理了指针\n");
        return val;
     }else if(tokens[op].type == TK_MS){
        uint32_t val0 = -eval(op+1,q,success);
        //printf("处理了自减符号\n");
        return val0;
     }else{
      //printf("%u %u\n",val1,val2);
      word_t val1 = eval(p, op - 1,success);
      word_t val2 = eval(op + 1, q,success);
      switch (tokens[op].type) {
        case '+': return val1 + val2;
        case '-': return val1 - val2; 
        case '*': return val1 * val2;
        case TK_EQ: return val1 == val2;
        case TK_UEQ: return val1 != val2;
        case TK_H: return val1 && val2;
        case '/': 
          if(val2 == 0){
            printf("Error: Division by zero\n");
            *success = false;
            return 0;
          }
          return val1/val2;
        default:
          printf("出现了不该出现的符号\n");
          assert(0);    
      }
    }
  }
}

//判断表达式是否被一对匹配的括号包围着
bool check_parentheses(int p,int q){
  if(tokens[p].type!='(' && tokens[q].type!=')'){
    return false;
  }
  int paren_count = 0;
  for(int i =p;i<=q;i++){
    //进行计数
    if(tokens[i].type=='('){
      paren_count++;
    }
    if(tokens[i].type==')'){
      paren_count--;
    }
    //如果右括号大于左括号直接返回false或者，如果在中途等号为0了那么说明已经被拦截了
    //i不等于q是为了不要误判最后一个括号
    if(paren_count<=0&&i!=q){
      return false;
    }
  }
//对表达式进行检查后，进行最后的判断
  if(paren_count == 0){
    return true;
  }else{
    return false;
  }
}


//找主符号数
int find_main_op(int p,int q){
  //printf("p=%d q=%d\n",p,q);
  int op = -1;
  int paren_count = 0;
  int min_precedence = 9999;
  for(int i =p; i<=q; i++){
    //进行计数
    if(tokens[i].type=='('){
      paren_count++;
    }
    if(tokens[i].type==')'){
      paren_count--;
    }
    //当前在括号内
    if(paren_count == 0){
      int precedence = 0;
      if(tokens[i].type == '+' || tokens[i].type == '-'){
        precedence = 2;
      }else if(tokens[i].type == '*' || tokens[i].type == '/'){
        precedence = 3;
      }else if(tokens[i].type == TK_PT||tokens[i].type == TK_MS){
        precedence = 4;
      }else if(tokens[i].type == TK_EQ || tokens[i].type == TK_UEQ||tokens[i].type == TK_H){
        precedence = 1;
      }else{
        //重要不能删除(当不在括号里面时直接跳过,不进行更新)
        continue;
      }
      //相等时也更新为了满足后面的符号优先级更低。
      if(precedence <= min_precedence){
          min_precedence = precedence;
          op = i;
      }
    }
  }
  return op;
}

