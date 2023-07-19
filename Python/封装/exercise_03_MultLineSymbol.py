def print_char(char, times):
    print(char * times)


def print_multi(char, times):
    """打印多行符号

    :param char: 符号类型
    :param times: 符号打印次数
    """
    i = 0
    while i < 5:
        print_char(char, times)
        i += 1


print_multi("-", 50)
