#include <stdio.h>

void test()
{
    //int n = 1;  //局部变量只作用在作用域，用完后释放存储
    static int n = 1;  //static 改变局部变量的作用域
    n++;
    printf("%d\n",n);
    
}

//void test(); //因为头文件未包含，直接这样使用的无效；
extern void test();  //当头文件未包含test()函数时，可以使用 extern 关键字引用使用，但 仅仅作用于函数的调用，与调用函数的内部参数无关系

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