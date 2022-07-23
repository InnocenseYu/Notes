#include <stdio.h>


//////////////////////////////
//////// 函数传参的使用 ////////
//////////////////////////////

// 方法 1 通过 value_swap 函数无法完成交换 a,b 的值
void value_swap(int x, int y); // 函数声明一般放在头文件中

int main()
{
    int a = 10, b = 20;
    printf("a = %d, b = %d\n",a,b);
    value_swap(a,b);
    printf("a = %d, b = %d",a,b);

    return 0;
}

void value_swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

// 改进方法 2 ，通过指针操作地址，交换 a b 的值

void value_swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 10, b = 20;
    printf("a = %d, b = %d\n", a, b);
    value_swap(&a, &b);
    printf("a = %d, b = %d", a, b);

    return 0;
}

///////////////////////////////
////// 素数判断 函数调用 ///////
///////////////////////////////

int judge_prime(int a)
{
	int i = 0;
	for (i = 2; i <= sqrt(a); i++)
	{
		if (0 == a % i)
		{
			return 0;  // 如果判断为真则不是素数，直接跳出函数；
			           // 否则 a%i != 0, 一直循环判断，直到 i>sqrt(a) 不满足 i<=sqrt(a) 跳出循环，a 肯定是素数
		}

	}

	return 1;
}

int main()
{

	// 打印 100 - 200 之间的素数
	for (int i = 100; i <= 200; i++)
	{
		if (1 == judge_prime(i))
			printf("%d", i);
	}

	return 0;
}

/////////////////////////////////
//////// 闰年判断 函数调用 ////////
/////////////////////////////////

int is_leap_year(int year)
{
	if ((year % 400) == 0 || ((year % 100) != 0) && ((year % 4) == 0))
		return 1;
	else
		return 0;
}

int main()
{
	int year = 0;
	int count = 0;

	for (year = 1000; year < 2023; year++)
	{
		if (1 == is_leap_year(year))
		{
			printf("%d", year);
			count++;
		}

	}

	printf("\ncount = %d", count);

	return 0;
}


/////////////////////////////////
//////// 二分查找 函数调用 ////////
/////////////////////////////////

int binary_search(int arr[], int value, int len)  // 这里形参 arr 本质是指针，用来存放实参传过来的数组的地址
{
	int left = 0;
	//int sz = sizeof(arr) / sizeof(arr[0]); // 数组 num 传递给数组 arr 的不是整个数组值，而是数组首元素地址，即 arr[0] = num[0],
	                                         // 所以 sizeof(arr) 就是 sizeof(arr[0]), 结果为 1
	int right = len-1;
	//int mid = (left + right) / 2; // 必须放在循环体内，否则，因程序循环出来则不会执行该语句，进而导致死循环

	while(left <= right)  //for (; left <= right; )
	{
		int mid = (left + right) / 2;

		if (value> arr[mid])
		{
			left = mid + 1;
		}

		else if (value < arr[mid])
		{
			right = mid - 1;
		}

		else
		{
			return mid;
		}

	}

	//while 循环之外：left > right 跳出，没有找到，结束程序 返回 0
	return 0;
}

int main()
{
	int num[] = { 2, 3, 4, 5, 6, 9};
	int input = 0;
	(void)scanf("%d", &input);

	int sz = sizeof(num) / sizeof(num[0]);
	int info = binary_search(num, input, sz);
	if (info)
		printf("%d", info);

	return 0;
}


