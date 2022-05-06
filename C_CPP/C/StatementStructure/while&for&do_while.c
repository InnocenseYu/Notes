#include <stdio.h>

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