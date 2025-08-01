#!/usr/bin/env python3

from sys import argv

#要操作的bin文件
bin = argv[1]
#参数最大长度
max_len = int(argv[2])
#镜像中用于标记参数位置的占位符
placeholder = argv[3]
#要注入的参数字符串
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
#找占位符
idx = data.find(str.encode(placeholder))
#没找到占位符，找到返回偏移量，没找到返回-1
if idx == -1:
    print("Error: placeholder not found!\n")
    exit(1)
#将文件指针移动到指定的偏移位置
fp.seek(idx)
#构造一个固定长度的字节串 用于将传入的参数字符串 mainargs 填充到指定的最大长度 max_len，不足部分用空字符（\0）补齐。
#返回值是个字符串
mainargs_pad = str.encode(mainargs) + ((max_len - len(mainargs)) * str.encode("\0"))
#这步是防止程序员手滑，确保最终长度和期望一致，避免破坏镜像结构。
if len(mainargs_pad) != max_len:
    print("Error: len(mainargs_pad) != max_len\n")
    exit(1)
#覆盖的写入
fp.write(mainargs_pad)
fp.close()
