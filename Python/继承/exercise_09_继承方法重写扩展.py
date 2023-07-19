class Shape:
    def __init__(self, name):
        self.name = name
        print("我是父类")

    def area(self):
        print("我是父类area方法")


class Square(Shape):
    # __init__()方法扩展重写，父类 Shape 中的__init_()方法被覆盖将不会被调用
    # def __init__(self, name, length):
    #     self.name = name
    #     self.length = length
    #     print("我是子类")

    # __init__()方法扩展重写，父类 Shape 中的__init_()方法被调用
    # def __init__(self, name, length):
    #     Shape.__init__(self, name)
    #     self.length = length
    #
    # __init__()方法扩展重写，父类 Shape 中的__init_()方法被调用，非常建议使用该类扩展重写
    def __init__(self, name, length):
        super().__init__(name)
        self.length = length

    # 父类 Shape 实例方法 area 覆盖重写
    def area(self):
        print(f"{self.name} 的面积是 {self.length * self.length}")


s = Square("正方形", 4)
s.area()
