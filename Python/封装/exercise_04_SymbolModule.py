def print_char(char, times):
    """打印单行符号

    :param char: 分割线符号
    :param times: 打印个数
    """
    print(char * times)


def print_multi(char, times):
    """打印多行符号

    :param char: 符号类型
    :param times: 符号打印个数
    """
    i = 0
    while i < 5:
        print_char(char, times)
        i += 1


name = "shaun_create"
