# 参考 exercise_09_继承方法重写扩展
class C(object):

    def __init__(self, x):
        self.__x = x

    def set_x(self, x):
        self.__x = x

    def get_x(self):
        print(f"__x is {self.__x}")

    def __private_func(self):
        pass


c = C(2)
# c.__x  # 访问错误，提示无属性 '__x'
c.get_x()
# '__x is 2'
c.set_x(5)
c.get_x()
# '__x is 5'
# c._C.__x  # 特殊方法访问私有变量，避开私有变量无法访问的问题,
# 5
print(c.__dict__)
# {'_C__x': 5}
c.__y = 0  # python 的动态性，动态添加私有变量
print(c.__dict__)
# {'_C__x': 5, '__y': 0}  # 动态添加的私有变量 __y 名字并没有被改编为 _C__y
