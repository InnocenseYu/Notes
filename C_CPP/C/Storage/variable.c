#include <stdio.h>

void test()
{
    //int n = 1;  //局部变量只作用在作用域，用完后释放存储
    static int n = 1;  //static 改变局部变量的作用域
    n++;
    printf("%d\n",n);
    
}

int main()
{
    int i = 0;
    while(i<3)
    {
        test(); //局部变量n只作用在test()作用域，用完后释放存储
        i++;
    }

    return 0;
}