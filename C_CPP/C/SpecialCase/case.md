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

### 冒泡排序
```C

/////////////////////////////
///////// 冒泡排序（升序） ///////////
/////////////////////////////

void bubble_sort(int arr[], int sz)
{
	
    // int sz = sizeof(arr) / sizeof(arr[0]);  //实际上传递过去的是数组 arr 首元素的地址 &arr [0], 则sz在sizeof函数的作用下sz=4Byte/4Byte

    // 确定冒泡排序的趟数
 	int i = 0;
	for (i = 0; i < sz - 1; i++) // 每一趟冒泡排序，将最大的元素放在数组最后, 只需操作 sz-1 躺将 sz-1 个元素放到最后即可，最后一个元素自动归位。
	{
		int flag = 1;// 假设这一趟要排序的数据已经有序
	
		int j = 0;
    	for (j = 0; j < sz-1-i; j++) //sz -1 -i, 解释：sz -1, 每趟sz个元素，只需比较sz -1次；-i (-0)表示去掉第 i+1（1） 躺已经完成的 i+1（1） 个升序的最大值，它们已经排放在最后了，不需要排序；i = 0，第一趟需要交换 sz-1 次；
		{
			if(arr[j] > arr[j + 1])
			{
				int tmp = arr[j]; //比较相邻两个元素的大小，交换
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;

			    flag = 0;// 本趟排序的数据其实不完全有序
			}
		}
		if (flag == 1) // flag 值没变，说明本躺排序没有进行元素交换，已经有序，跳出排序
		{
			break;  
		}
	}
}

```

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

[变量类型强制转换](../Storage%26Variable/storage%26variable.md/#变量类型强制转换)
```C
void srand(unsigned seed);    //seed 必须是时刻变化的量，unsigned类型，可以使用时间戳代替，使用time函数获取时间戳

time_t time(time_t* const timer);  //函数包含在 time.h,time函数返回值类型是time_t，右键查看定义，time_t类型是使用typedef 重命名的long型

srand((unsigned) time(NULL));  //调用一次即可
//time函数返回值类型与srand函数输入参数类型不同，强制转换,类型使用括号包裹；
//time函数输如参数为指针类型，防止空指针，初始化为NULL
```

### 二进制 位异或
```C
// 2^2 = 0
// 3^3 = 0
// a^a = 0
// 0^2 = 2

// a^a = 0
// 0^a = a

// 满足交换律
//a^b^a = a^a^b = b

变量的交换：
// 示例1：
a = a^b;
b = a^b; //a
a = a^b //a^b^a = a^a^b = b

1^2^3^4^5^1^2^3^4 = 1^1^2^2^3^3^4^4^5 = 0^0^0^0^5 = 5

加密：
// 示例2：
//第一步，明文（text）与密钥（key）进行异或运算，可以得到密文（cipherText）
text ^ key = cipherText

//第二步，密文与密钥再次进行异或运算，就可以还原成明文
cipherText ^ key = text

//原理很简单，如果明文是 x，密钥是 y，那么 x 连续与 y 进行两次异或运算，得到自身
(x ^ y) ^ y
= x ^ (y ^ y)
= x ^ 0
= x

数据备份
// 文件 x 和文件 y 进行异或运算，产生一个备份文件 z。
x ^ y = z

//以后，无论是文件 x 或文件 y 损坏，只要不是两个原始文件同时损坏，就能根据另一个文件和备份文件，进行还原。
x ^ z
= x ^ (x ^ y) 
= (x ^ x) ^ y
= 0 ^ y
= y

上面的例子是 y 损坏，x 和 z 进行异或运算，就能得到 y

```


### 水仙花数

```C
// 水仙花数: 指一个 n 位数，其各位数字的 n 次方之和 等于该数本身，如：153 = 1^3 + 5^3 + 3^3，则153是一个水仙花数

// 求出0~100000之间的所有水仙花数并输出

// 几位数
int num_count(n)
{
	int count = 1;

	while (n /= 10)
	{
		count++;
	}

	return count;
}

// n^k
int Pow(int n, int k) // 5,3
{
	if (k > 0)
	{
		return n * Pow(n, --k); // 5*Pow(5,2) == 5*5*Pow(5,1) == 5*5*5*1
	}
	else if (0 == k)
	{
		return 1; // 0^0 == 1
	}
	else
	{
		return (1 / (Pow(n, -k)));  // -k 将 k<0 转换为 k>0 即可使用 n*Pow(n, --k)
	}
}

void waterflower(int n)
{
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		int tmp = i; //一般不改变操作数，容易导致混乱
		while (tmp)
		{
			sum += Pow(tmp % 10, num_count(i)); // 遍历每一位的num_count(i)次方之和
			tmp /= 10; // 拿到除个位的数之外的十位、百位等
		}

		if (sum == i)
		{
			printf("%d\n", i);
		}
	}

}

int main()
{
	waterflower(100000);

	return 0;
}

```


