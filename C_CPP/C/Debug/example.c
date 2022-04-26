#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i = 0;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    for(i=0;i<=12;i++)  //将会导致arr数组寻址错误，访问越界
    {
        printf("arr[i]=0\n");
        arr[i] = 0;
        printf("arr[i] = %d\n",arr[i]);
    } //i=12,for循环中最后一个arr[i]=0;执行后，i=0，下个语句，i++,i=1,此时会陷入死循环；
      //可能的原因是：i和arr[12]同一个地址，为什么会是同一个地址呢？
      //

    system("pause");

    return 0;
}