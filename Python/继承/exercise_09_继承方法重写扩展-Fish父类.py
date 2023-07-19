import random as r


class Fish:
    def __init__(self):
        self.x = r.randint(0, 10)
        self.y = r.randint(0, 10)
        print("我是父类")

    def move(self):
        self.x -= 1
        print(f"我的位置坐标是(x, y): ({self.x}, {self.y})")


class Goldfish(Fish):
    pass


class Carp(Fish):
    pass


class Salmon(Fish):
    pass


# 问题：下面类的定义中 Shark 类虽然继承了Fish 类，
# 但是因为Shark 类的 __init__()方法与 Fish 类 __init__()方法同名，
# 因此父类 Fish 的 __init__()方法会被覆盖，但是 Fish 类本身的__init__()方法不会被改变
# 解决方法：函数重写扩展

class Shark(Fish):
    # def __init__(self):
    #     self.hungry = True
    #     print("我是子类")

    # 方法重写扩展，当前子类重写和父类都会调用
    def __init__(self):
        super().__init__()
        self.hungry = True
        print("我是子类")

    def eat(self):
        if self.hungry:
            print("吃货的梦想就是天天有的吃^_^")
            self.hungry = False
        else:
            print("太撑了,吃不下了!")


s = Shark()
s.move()
s.move()
s.eat()
s.eat()
