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

#include <isa.h>
/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
bool check_parentheses(int p,int q);
int find_main_op(int p,int q);
word_t eval(int p,int q);
enum {
  //空格串的token类型是TK_NOTYPE
  TK_NOTYPE = 256, TK_EQ,
  TK_NUM,

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"\\-", '-'},
  {"\\*", '*'},
  {"\\/", '/'},
  {"\\(", '('},
  {"\\)", ')'},
  {"[0-9]+", TK_NUM},
  {"==", TK_EQ},        // equal
  
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
static Token tokens[512] __attribute__((used)) = {};
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
        int substr_len = pmatch.rm_eo - pmatch.rm_so;
        // Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
        //     i, rules[i].regex, position, substr_len, substr_len, substr_start);
            

        //移动位置
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
          //类型
          tokens[nr_token++].type = rules[i].token_type;
          break;

          case TK_NUM:
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
          default: TODO();
        }

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

  word_t result =  eval(0,nr_token-1);
  /* TODO: Insert codes to evaluate the expression. */
  //TODO();
  
  //printf("expr中的result: %u \n",result);
  *success = true;
  return result;
}



//递归求值函数
word_t eval(int p,int q) {
  if (p > q) {
    /* Bad expression */
    printf(" Bad expression!");
    return 1;
  }
  else if (p == q) {
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
    return (unsigned int)atoi(tokens[p].str);
  }
  else if (check_parentheses(p, q) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1);
  }
  else {
    int op = find_main_op(p,q);
     if(op==-1){
        printf("Error: No operator found between %d and %d\n", p, q);
         return (unsigned int)atoi(tokens[p].str); // 假设表达式是单个操作数
     }
    
    word_t val1 = eval(p, op - 1);
    word_t val2 = eval(op + 1, q);

    switch (tokens[op].type) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/': return val1 / val2;
      default: assert(0);
    }
  }
}

//判断表达式是否被一对匹配的括号包围着
bool check_parentheses(int p,int q){
  if(p >= q ||tokens[p].type!='('||tokens[q].type!=')'){
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

    //如果右括号大于左括号直接返回false
    if(paren_count<0){
      return false;
    }
  }
  return paren_count == 0;
}


//找主符号数
int find_main_op(int p,int q){
  printf("Searching op between p=%d, q=%d: ", p, q);
  int op = -1;
  int paren_count = 0;
  int min_precedence = 9999;
  for(int i =q; i>=p; i--){
    //进行计数
    if(tokens[i].type=='('){
      paren_count++;
    }
    if(tokens[i].type==')'){
      paren_count--;
    }
    //当前不在括号内
    if(paren_count == 0){
      int precedence = 0;
      if(tokens[i].type == '+' || tokens[i].type == '-'){
        precedence = 1;
      }else if(tokens[i].type == '*' || tokens[i].type == '/'){
        precedence = 2;
      }else{
        continue;
      }

      //相等时也更新为了满足后面的符号优先级更低。
      if(precedence <= min_precedence){
          min_precedence = precedence;
          op = i;
      }
    }
  }
        printf(" %c\n",tokens[op].type);
  return op;
}

