# 方法1：使用全局变量
# 注意：非万不得已，尽量不要使用全局变量，因为它会污染命名空间
class D(object):

	def __init__(self, name):
		self.name = name

	def __del__(self):
		global x
		x = self


d = D("relive")
print(d)
# <_main_.D object at 0x00000140C7AD0910>
x = None
del d  # 删除内存中的实例对象
# d 实例被赋值给全局变量 x, 使用 del d 命令后，虽然实例对象 d 被删除，但是全局变量x的值只有在程序退出时才会消失
print(x.name)
# "relive"
