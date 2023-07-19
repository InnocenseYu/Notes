class Shape:
    def __init__(self, name):
        self.name = name

    def area(self):
        pass


# class Square(Shape):
#
#     # __init__()方法扩展重写，父类 Shape 中的__init_()方法将不会被调用
#     def __init__(self, name, length):
#         super().__init__(name)
#         self.length = length
#
#     def area(self):
#         print(f"{self.name} 的面积是 {self.length * self.length}")


class Square(Shape):

    # __init__()方法扩展重写，父类 Shape 中的__init_()方法将不会被调用
    def __init__(self, length):
        self.length = length

    def area(self):
        print(f"正方形的一边长为：{self.length}")
        return f"正方形的一边长为：{self.length}"  # 返回值需要打印才能显示


s = Square(4)
print(s.area())
