## 一些特殊案例

### 程序死循环
- 变量越区操作，导致不可控
- ![变量存储区规划1](../Storage&Variable/stack.png)
- ![变量存储区规划2](../Storage&Variable/stack0.png)
- [栈区的使用](../Storage&Variable/storage&variable.md/#栈区的使用)

### 辗转相除法 (欧几里得算法)
- 求最大公约数 (Greatest common factor/divisor，GCF/GCD)
  - 关于两个数 a b 最大公约数的求法，不需要比较 a b 大小
  - 小数除以大数，商为零，余数是自己
- 求最小公倍数 (Least Common Multiple), LCM(a,b)= (a*b)/HCD(a,b)

### 闰年、平年的使用
- 能被400整除的年份
- 能被4整除不能被100整除的年份
```C
if((year % 400) == 0 || ((year % 100) != 0) && ((year % 4) == 0))
```
### 质数、素数判断
- 只能被1和它本身整除的数是素数
> 方法1
```C
        for (j = 2; j < i; j++) //j作为i的试除因子，在开区间(1,i)被i除
			{
				if (i % j == 0) //只要碰到一个能被整除就不是素数,跳出继续试除，
                                //跳出该for循环有两个原因，1、直接能被整除，2、j>=i
					break;
			}

			if (j == i)
				printf("%d ", i);
```

> 方法2
- 当 i 不是质数时一定可以分解成：i = a*b，如16 = 2*8 = 4*4，
- 所以在 i 的质因数中只要找一个就已经可以判断出来不是质数，另一个丢弃即可，所以选用较小的那个质因数
- 同时，min(a,b)<=sqrt(i), 所以 i 试除的因子j<=sqrt(i)即可，并且sqrt(i) < i/2,也可写成j < i/2

```C
    {
			for (j = 2; j <=sqrt(i); j++)
			{
				if (i % j == 0) //只要碰到一个能被整除就不是素数,跳出继续试除，
                                //跳出该for循环有两个原因，1、直接能被整除，2、j>=i
					break;
			}

			if (j > sqrt(i))
				printf("%d ", i);
	}
```
> 方法3
- 偶数不可能是素数
- 那么在 i 是奇数中查找即可
```C
for (i = 3; i < 100; i+=2) // i从奇数开始, i+=2, 判断下个奇数
	{
			for (j = 2; j <=sqrt(i); j++)
			{
				if (i % j == 0) //只要碰到一个能被整除就不是素数,跳出继续试除，
                                //跳出该for循环有两个原因，1、直接能被整除，2、j>=i
					break;
			}

			if (j > sqrt(i))
				printf("%d ", i);
			
	}
```

### 符号位控制
- 定义一个标记使用


### 随机数
- rand()函数生成的是伪随机数，虽然本次生成的数字是随机数，但是每次运行数字是相同的
- 可以使用srand()函数为rand函数生成种子
- 使用rand()之前未使用srand()时，相当于使用srand(1)
- 当使用rand()之前使用srand()时，且是srand(2)，虽然rand()运行的随机值同srand(1)不同，但是二次运行时也是不变的；
- 所以，srand(unsigned seed)的 seed必须**时刻变化**，可以使用**时间戳**
- 时间戳
  - 时间戳(秒) = 当前时间 - 计算机起始时间(1970.1.1.0:0:0)
  - 使用 time()函数获取

### 变量类型强制转换
```C
void srand(unsigned seed);    //seed 必须是时刻变化的量，unsigned类型，可以使用时间戳代替，使用time函数获取时间戳

time_t time(time_t* const timer);  //函数包含在 time.h,time函数返回值类型是time_t，右键查看定义，time_t类型是使用typedef 重命名的long型

srand((unsigned) time(NULL));  //调用一次即可
//time函数返回值类型与srand函数输入参数类型不同，强制转换,类型使用括号包裹；
//time函数输如参数为指针类型，防止空指针，初始化为NULL
```