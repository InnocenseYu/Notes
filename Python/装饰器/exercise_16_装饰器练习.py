def begin_end(fn):  # 其他函数的函数名fn当参数
    """
         用其他函数来扩展该函数, 使其他函数可以在 执行前 打印 开始执行, 执行后 打印 执行结束
    """

    # 创建一个新函数, 功能由输入函数扩展
    def new_function(*args, **kwargs):

        print("开始执行...")

        # 调用被扩展的函数
        result = fn(*args, **kwargs)

        print("执行结束...")

        # 返回函数执行结果
        return result

    # 返回新函数
    return new_function


@begin_end
def add_plus(a, b):
    r = a + b
    return r


add_plus(1, 2)
# 相当于 add_plus = begin_end(add_plus), add_plus()
