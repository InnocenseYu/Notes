
"""案例
需求
1.在 Dog 类中封方法 game
    普通狗只是简单的玩耍
2.定义 XiaoTianQuan 继承自 Dog, 并且重写 game 方法
    哮天犬需要在天上玩耍
3.定义 Person 类, 并且封装一个和狗玩的方法
    在方法内部, 直接让狗对象调用 game 方法
"""


class Dog(object):

    def __int__(self, name):
        self.name = name

    def game(self):
        print("%s 蹦蹦哒哒" % self.name)


class XiaoTianQuan(Dog):

    def game(self):
        print("%s 也可以飞翔" % self.name)


class People(object):

    def __int__(self, name):
        self.name = name

    def play(self, dog):
        # 不在初始化方法中的参数也可以在自定义方法中作为参数使用
        print("%s 和 %s 快乐的玩耍" % (self.name, dog.name))
        dog.game()


# 1、创建一个狗对象
wangcai = Dog("旺财")
# wangcai = XiaoTianQuan("旺财")

# 2、创建一个小明对象
xiaoming = People("小明")

# 3、让小明调用和狗玩的方法
xiaoming.play(wangcai)
# 小明 和 旺财 快乐的玩耍
# Dog 类创建的 wangcai, 输出结果为：旺财 蹦蹦哒哒
# XiaoTianQuan 类创建的 wangcai，输出结果为：旺财 也可以飞翔

"""
1、多态本质是对象的多态，而继承的本质是类的继承，前者是实现，后者是抽象
2、多态的更主要的作用是在开发时只知道现在有DOG，不能预想到将来可能增加CAT，BIRD等等的时候
3、现在甚至可以直接写成object.game，这样在开发之初就保留了程序未来的扩展性
"""
