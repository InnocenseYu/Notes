#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n = 0;
    while(i<10)
    {
        //n++; 放到此处时，输出0 1 2 3 4 6 7 8 9 10，排除5
        if(5 == n)
            continue;
        printf("%d ",n); //输出0 1 2 3 4 在5死循环，因为n==5时，返回循环，判断为真，继续执行continue
        n++;
    }
}


int main()
{
	/*
    int ch = getchar();
	putchar(ch);              //putchar printf 每次只能输出一个int 型字符
	printf("%c", ch);
    */

	int ch = 0;
	while ((ch = getchar()) != EOF)  // EOF: end of file，可以使用键盘ctrl + z输入
		putchar(ch);

	return 0;

}

int main()
{
    int i = 0;
    for(;i<=10;i++)
    {
        if(i==5)
        break;
        printf("%d ",i);
    }

    return 0;
}

///////////////////////
//计算n的阶乘////////
/////////////////////

int main()
{
    int k = 1;
    int n = 0;
    printf("please input n:");
    scanf("%d",&n);
    int i = 0;
    for(i=1 ; i<=n; i++)
    {
        k = k*i;
    }
    printf("n! = %d\n",k);

    return 0;
}

/////////////////////
// 1+2!+3!+...+10!///
/////////////////////
int main()
{
    
    int n = 0;
    int sum = 0;
    printf("please input n:");
    scanf("%d", &n);

    int j = 0;
    for (j = 1; j <= n; j++)
    {
        int k = 1;
        int i = 0;
        for (i = 1; i <= j; i++)
        {
            k = k * i; //每个j值的阶乘，注意k变量要在作用域内初始化。
                       //否则，当在j循环之外的话，每次i值变化，k的值将不会被重置为1，将保留上次使用的值
            //阶乘计算，i<=j
        }

        sum += k;     

    }
    printf("sum = %d\n", sum);

    return 0;
}

////////////////////////////////////////////
//////以上代码优化时间复杂度O(n^2) -> O(n)////
///////////////////////////////////////////
int main()
{
    int factorial = 1; 
    int sum = 0;  //注意 factorial 和 sum，int 型变量值是否溢出（4byte -> 32bit，取值范围0-2^32）

    int n = 0;
    printf("please input n:");
    scanf("%d",&n);

    int i = 0;
    for(i=1 ; i<=n; i++)
    {
        factorial = factorial*i;
        sum = sum + factorial;
    }
    printf("n! = %d\n",sum);

    return 0;
}


/////////////////////////////////////////
/////在一个有序数组中查找具体的某个数字n////
/////////////////////////////////////////
void binsearch(int x, int arr[])
{
    printf("input x  to find:");
    scanf("%d",&x);

    int len = sizeof(arr)/sizeof(arr[0]);

    int i = 0;
    for(i = 0; i<len; i++)
    {
        if(arr[i] == x)
        {
            printf("%d\n",i);
            break;
        }
    }
    if(i ==len)
        printf("can't find x");

}

// 以上程序算法优化, arr数组有序,假设arr[] = {9,8,7,6,5,4,3,2,1,0}
// 二分查找算法，时间复杂度O(log_2(n))
void binsearch(int x, int arr[])
{
    printf("input x  to find:");
    scanf("%d",&x);

    int len = sizeof(arr)/sizeof(arr[0]);
    int left = 0;
    int right = len -1;
    int mid = (left + right)/2;
    for(; left <= right; )
    {
        if(arr[mid] > x)
            right = mid -1;
        else if(arr[mid] < x)
            left = mid +1;
        else 
        {
            printf("%d",mid);
            break;
        }
    }
    
}

///////////////////////////////////////////
///////多个字符从两端移动 向中间汇聚//////////
///////////////////////////////////////////
int main()
{
	char str1[] = "Welcome to China!";
	char str2[] = "#################";

	int len = strlen(str1);
	int left = 0;
	int right = len - 1;

	for (; left <= right; )
	{
		str2[left] = str1[left];
		str2[right] = str1[right];
		/*strcpy(str2[left], str1[left]);
		strcpy(str2[right], str1[right];*/ //strcpy()操作整个字符串的
		printf("%s\n", str2);
		Sleep(1000);    // 休息1s
		system("cls");   // 清屏
		
		left++;
		right--;

	}
	printf("%s\n", str2);

	return 0;
}

///////////////////////////////////
/////模拟用户登录场景，只有三次机会///
///////////////////////////////////
int main()
{
    char password[20] = {0};
    int i = 0;
    for(i = 0; i<3; i++)
    {
        printf("input your password:");
        scanf("%s",password); //scanf()函数直接获取单词，字符串的话可能因为空格问题导致获取失败
        if((strcmp(password,"lixinyu") == 0)
        {
            printf("login success!");
            break;
        }
                
    }
    if(3 == i)
    printf("login fail~");

    return 0;
}

////////////////////////////////
////////三个数从大到小排列////////
////////////////////////////////
int main()
{
    int arr[5] = {0};
    printf("input three number:");

    int i = 0;
    for (i = 0; i < 3; i++)
    {
        scanf("%d", &arr[i]);  // 

    }

    int sz = sizeof(arr) / sizeof(arr[0]);

    int j = 0;
    for (j = 0; j < sz - 1; j++)
    {
        int flag = 1;
        int k = 0;
        for (k = 0; k < sz - 1 - j; k++)
        {
            if (arr[k] < arr[k + 1])
            {
                int tem = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = tem;
                flag = 0;
            }
        }

        if (1 == flag)
            break;

    }

    int n = 0;
    for (n = 0; n < 3; n++)
    {
        printf("%d ", arr[n]);
    }

    return 0;

}


////////////////////////////////
////////100以内3的倍数//////////
////////////////////////////////
int main()
{

	for (int i = 1; i < 100; i++)
	{
		if ((i % 3) == 0)
		{
			printf("%d ", i);
		}
	}

	return 0;
}

//////////////////////
///////最大公约数,最小公倍数//////
//////////////////////
int main()
{
	int a = 0, b = 0, r = 0;
	scanf("%d %d", &a, &b);

    int j,k;
    j = a;
    k = b;

	//if (a > b)            //不需要比较，因为就算a = 2, b = 4, a%b == 2,下次循环
							//b = 4赋值给a, a = 4
							//r = 2赋值给b,b=2     //此时已经交换过来a>b
	//{
		while (j % k)
		{
            r = j % k;
			j = k;
			k = r;
		}
		printf("Mostest Common Divisor: %d", k);
        printf("Least Common multiple: %d",(a*b)/k);
	//}
	//else
	//{
	//	int tem = a;
	//	a = b;
	//	b = tem;

	//	while (a % b)
	//	{
	//		r = a % b;
	//		a = b;
	//		b = r;
	//	}
	//	printf("%d", b);
	//}
	//while()

	return 0;
}


/////////////////////////////////
//////////平年 闰年判断///////////
/////////////////////////////////

int main()
{
   int year = 0;
   
   
   for (int i = 0; i < 100; i++)
   {
       printf("input a year: ");
       scanf("%d", &year);
       
       if ((year % 400) == 0)
           printf("yes!\n");
       else if (((year % 100) != 0) && ((year % 4) == 0))
           printf("yes!\n");
       else
           printf("no run year!\n");
   }

   return 0;
}


/////////////////////////////////
//////////计算2023年内所有闰年/////
/////////////////////////////////
int main()
{
    int year = 0;
    int count = 0;

    for (year = 0; year < 2023; year++)
    {
    
        if ((year % 400) == 0)
        {
            printf("%d ", year);
            count++;
        }
                
        else if (((year % 100) != 0) && ((year % 4) == 0))
        {
            printf("%d ", year);
            count++;
        }

    }
            
    //方法二：
    for (year = 0; year < 2023; year++)
    {
    
        if((year % 400) == 0 || ((year % 100) != 0) && ((year % 4) == 0))
        {
            printf("%d ", year);
            count++;
        }

    }
    
    
    printf("\ncount = %d", count);

    return 0;
}

/////////////////////////////////
//////////质数 素数判断 打印 /////
/////////////////////////////////

int main()
{
	int i = 0;
	int j = 0;
	for (i = 2; i < 100; i++)
	{
		if (2 == i)
			printf("%d ", i);
		else
		{
			for (j = 2; j < i; j++)
			{
				if (i % j == 0) //只要碰到一个能被整除就不是素数,跳出继续试除，跳出该for循环有两个原因，1、直接能被整除，2、j>=i
					break;
			}

			if (j == i)
				printf("%d ", i);
		}
			
	}

	return 0;
}
//方法二
// 当 i 不是质数时一定可以分解成：i = a*b，如16 = 2*8 = 4*4，
// 所以在 i 的质因数中只要找一个就已经可以判断出来不是质数，另一个丢弃即可，所以选用较小的那个质因数
// 同时，min(a,b)<=sqrt(i), 所以 i 试除的因子j<=sqrt(i)即可，并且sqrt(i) < i/2,也可写成j < i/2
int main()
{
	int i = 0;
	int j = 0;
	for (i = 2; i < 100; i++)
	{
		if (2 == i)
			printf("%d ", i);
		else
		{
			for (j = 2; j <=sqrt(i); j++)
			{
				if (i % j == 0) //只要碰到一个能被整除就不是素数,跳出继续试除，跳出该for循环有两个原因，1、直接能被整除，2、j>=i
					break;
			}

			if (j > sqrt(i))
				printf("%d ", i);
		}
			
	}

	return 0;
}

/////////////////////////////////
//////////1-100数字内有几个9 /////
/////////////////////////////////
int main()
{
    int count = 0;
    for(int i = 1; i<=100; i++)
    {
        if(9 == i%10)
        count++;
        if(9 == i/10)
        count++;

        //使用else if(9 == i/10)的话虽然会找到十位为9的数,但是个位为9的会被排除掉
        //只使用一个或的话，也会漏掉

    }

    printf("%d",count);

    return 0;
}

///////////////////////
///计算分数加减求和/////
///////////////////////
int main()
{
	//int sum = 0;
	double sum = 0.0;

	int i = 0;
	for (i = 1; i <= 100; i++)
	{
		int n = 1;
		if (0 == i % 2)
		{
			n = -1;
		} //偶数位符号控制
			
		//sum += n * (1 / i);    // 1/i 没有考虑小小数问题，这里使用浮点型定义，可以将1 改为1.0，sum 定义为double型
		sum += n * (1.0 / i);
		//n = -n; //符号控制
	}

	printf("%lf\n", sum);

	return 0;
}