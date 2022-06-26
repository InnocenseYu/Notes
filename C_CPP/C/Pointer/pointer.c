#include <stdio.h>

#define N_VALUES 5

int main()
{
    float value[N_VALUES];
    float* vp;
    for(vp=&value[N_VALUES];vp>&value[0];)
    {
        //故此语句有问题；
        // *vp-- = 0; //vp-- 是先使用当前*vp赋值后，再自减；即*vp = 0后，vp--；
                     //当vp = 1时，*vp指向的value[1]=0, 之后，vp=vp-1=0=&value[0],不满足vp>&value[0]故跳出循环，无法完成对&value[0]的赋值;
        
        *--vp = 0;   //vp先自减后，再操作赋值语句；
                     //当vp=1时，--vp为vp=vp-1=0,*vp指向的value[0]=0;
    }
}


//二级指针
int main()
{
    int a = 10;
    int* pa = &a;
    int** ppa = &pa; //ppa就是二级指针
    int*** pppa = &ppa; //pppa就是三级指针

    printf("a = %d\n",a);
    printf("*pa = %d\n",*pa);
    printf("**ppa = %d\n",**ppa);
    printf("***pppa = %d\n",***pppa);
    
    return 0;
}

// a = *pa = **ppa = ***pppa
// &a = pa = *ppa = **pppa
// pppa存储ppa的地址，*pppa即为ppa的值（ppa的值为pa的地址），**pppa即为pa的值（pa的值为a的地址），则***pppa即为a的值


/////////////////////////////////////////////
////// 数组作为形参的两种方式  ////////////////
/////////////////////////////////////////////

//方法1 形参使用数组
void print(int arr[], int sz)
{
    for(int i = 0; i<sz; i++)
    {
        printf("%d ", arr[i]);
    }
}

//方法2 形参使用指针
void print(int* p, int sz)
{
    for(int i = 0; i<sz; i++)
    {
        printf("%d ",*(p+i));
    }
}

int main()
{
    int arr[] = {1,3,4,5,6,7,8};
    int sz = sizeof(arr)/sizeof(arr[0]);
    print(arr,sz);

    return 0;
}