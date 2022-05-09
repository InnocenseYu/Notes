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