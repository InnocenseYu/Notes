#include <stdio.h>



//////////////////////////////
//////// 函数传参的使用 ////////
//////////////////////////////

//方法1 通过value_swap函数无法交换a,b的值
void value_swap(int x, int y);

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

//改进方法2 ，通过指针操作地址，交换a b的值
void value_swap(int* x, int *y);

int main()
{
    int a = 10, b = 20;
    printf("a = %d, b = %d\n", a, b);
    value_swap(&a, &b);
    printf("a = %d, b = %d", a, b);

    return 0;
}

void value_swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}