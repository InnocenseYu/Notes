# 全局命名空间
# gl_var = "我是全局变量"
# print(f"全局作用域命名空间变量：{locals()}")


# 函数命名空间
def hello_variable():
    a = 10
    print(f"函数命名空间：{locals()}")

    def inner():
        b = 'B'
        print(f"函数内函数的命名空间：{globals()}")
    return inner


# hello_variable()
hello_variable()()


# 类命名空间
# class C(object):
#
#     cls_a = 10
#     print(f"类命名空间：{locals()}")
#
#     def __init__(self, x):
#         self.__x = x
#         # print(f"实例方法命名空间：{locals()}")
#
#     def get_x(self):
#         print(f"__x is {self.__x}")
#         # print(f"实例方法命名空间：{locals()}")  # 只会打印 命名空间中 self变量
#
#
# c = C(2)
# c.get_x()
