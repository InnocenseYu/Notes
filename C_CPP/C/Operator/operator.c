#include <stdio.h>

/////////////////////////////////////////////
/////求一个整数存储在内存中的二进制中1的个数/////
/////////////////////////////////////////////

int main()
{
    int num = -1;
    int i = 0;
    int count = 0; //计数
    for(i=0; i<32; i++)
    {
        if( num & (1 << i) )
        count++;
    }

    //方法二
    // while(num)
    // {
    //     count++;
    //     num = num&(num-1);
    // }  

    printf("num二进制中1的个数 = %d\n",count);

    return 0;
}


/////////////////////////////////////////////
//////////将一个整数二进制某位置1//////////////
/////////////////////////////////////////////

int main()
{
    int a = 11; //将11的二进制位右数第二位置1
    a = a | (1<<2);// 1D = 00000001B; a = 00001111 = 00001011 | 00000100
    printf("%d\n", a); // a = 15
    a = a & (~(1<<2)); // a = 11
    printf("%d\n", -a); // -11
}