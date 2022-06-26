/////////////////////////////////
////////求解字符串长度 函数递归 ////////////////
/////////////////////////////////

int my_strlen(const char* str)
{
	if(*str != '\0')
		return 1+my_strlen(str+1);
	else
		return 0;

    // 大事化小原则：
    // my_strlen("hello");
    // 1+my_strlen("ello");
    // 1+1+my_strlen("llo");
    // 1+1+1+my_strlen("lo");
    // 1+1+1+1+my_strlen("o");
    // 1+1+1+1+1+my_strlen("");
    // 1+1+1+1+1+0 = 5

}

int main()
{
    char arr[] = "hello";
    int len = my_strlen(arr);

    printf("len = %d ", len);

    return 0;
}


///////////////////////////////////
/////// 数字各位打印 函数递归 ///////
///////////////////////////////////

int num_print(int num)
{
	if (num > 9)
		num_print(num / 10);
	//else //不能使用else判断 下面的语句必须执行
	printf("%d ",num % 10);

	// 执行逻辑：假设num 为 123

	/*第一次：123 大于9 执行迭代 12
	第二次：12 大于9 执行迭代 1
	第三次：1 小于9 执行打印 求余，返回到 第二次函数结果
	第二次：执行打印 求余为 2，返回到 第一次函数结果
	第一次：执行打印 求余为 3 */
	return 0;
}

int main()
{
	int number = 0;
	printf("请输入数字：");
	scanf("%d", &number);

	num_print(number);

	return 0;
}


//////////////////////////////////////////
//////// n阶层求解 函数递归 ////////////////
//////////////////////////////////////////

int factorial(int n)
{
    if(n>1)
        return n*factorial(n-1);
    else
        return 1;

}

//////////////////////////////////////////
//////// 斐波那契数列 函数递归 ////////////////
//////////////////////////////////////////

//方法一
int m = 0;

int fib(int n)
{
	if (3 == n) 
	{
		m++;
	}
	
	if (n <= 2)
	{
		
		return 1;
	}
		
	else
		return fib(n - 1) + fib(n - 2); // 迭代重复次数较多
}

// 方法二
int fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1; //输入 1 2时，不进入循环，直接输出c
	for (int i = 3; i < n+1; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	
	/*while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}*/

	return c;
}

///////////////////////////////////////////////////
////////////// 数组前后反转，不使用库函数/////////////
///////////////////////////////////////////////////

//// 方法1
//void reverse_string(char arr[])
//{
//	int start = 0;
//	int end = strlen(arr) - 1;
//	char tmp = 0;
//
//	if (start <= end)
//	{
//		tmp = arr[start];
//		arr[start] = arr[end];
//		arr[end] = tmp;
//
//		start++;
//		end--;
//	}
//
//}


int my_strlen(char* arr) // 形参使用的是指针，也可以这样写 char arr[], 函数内部语句不用变
{
	int count = 0;
	while (*arr != '\0') // 只要是地址就可以使用 * 符号符操作
	{
		count++;
		arr++;
	}

	return count;
}

// 方法2 递归实现
void reverse_string(char arr[])  // arr[] = "abcdef\0"
{
	char tmp = arr[0];
	int len = my_strlen(arr); // 为获取数组长度做准备
	arr[0] = arr[len-1]; 
	arr[len - 1] = '\0'; // 构造my_strlen函数的判断条件
	//arr[len - 1] = tmp; // 可否在这个位置交换？完成首次首尾交换？
	// 不行。假设 arr[] = "abcdef\0"，到达该句完成第一次首尾交换，arr[] = "fbcdea\0",下次执行迭代的话，应该操作"bcde\0", 所以迭代之前 a 的位置应该是 \0;
	
	if (my_strlen(arr+1) >= 2)
	{
		reverse_string(arr + 1); // 函数入口 形参为数组，数组名也是地址，也可以使用 arr+1 操作
	}
	
	arr[len - 1] = tmp;
}


int main()
{
	char arr[] = "abcdef";
	reverse_string(arr);
	printf("%s", arr);

	return 0;
}