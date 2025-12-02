#!/usr/bin/env python3

from sys import argv

#要操作的bin文件
bin = argv[1]
#最大长度
max_len = int(argv[2])
#占位符
placeholder = argv[3]
# 输入的字符
mainargs = argv[4]

#对参数的长度进行检查
if len(mainargs) >= max_len:
    print("Error: mainargs should not be longer than {0} bytes\n".format(max_len))
    exit(1)
print("mainargs={0}".format(mainargs))

# 打开 bin 文件（二进制可读写）
fp = open(bin, 'r+b')
 # 全部读入内存
data = fp.read()
#找占位符的字节序列，找到返回偏移量，没找到返回-1
idx = data.find(str.encode(placeholder))
#没找到
if idx == -1:
    print("Error: placeholder not found!\n")
    exit(1)
#将光标移动到指定的偏移位置
fp.seek(idx)
#构造一个固定长度的字节串用于将传入mainargs填充到指定的最大长度max_len，不足部分用空字符（\0）补齐
#encode是将文本 ---> 二进制
mainargs_pad = str.encode(mainargs) + ((max_len - len(mainargs)) * str.encode("\0"))

# 再次确定一下
if len(mainargs_pad) != max_len:
    print("Error: len(mainargs_pad) != max_len\n")
    exit(1)

#覆盖的写入
fp.write(mainargs_pad)
fp.close()
