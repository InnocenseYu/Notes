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
    // a = *pa = **ppa = ***pppa = 10
    // &a = pa = *ppa = **pppa
    // pppa存储ppa的地址，*pppa即为ppa的值（ppa的值为pa的地址），**pppa即为pa的值（pa的值为a的地址），则***pppa即为a的值

    return 0;
}


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



/////////////////////////////////////
//////// 数组和指针的计算 ////////////
/////////////////////////////////////

int main()
{
    int a[] = {1,2,3,4};
    printf("%d\n",sizeof(a));        // 4*4 =16byte
    printf("%d\n",sizeof(a+0));      // 4
    printf("%d\n",sizeof(*a));       // 
    printf("%d\n",sizeof(a+1));
    printf("%d\n",sizeof(a[1]));
    printf("%d\n",sizeof(&a));
    printf("%d\n",sizeof(*&a));
    printf("%d\n",sizeof(&a+1));
    printf("%d\n",sizeof(&a[0]));
    printf("%d\n",sizeof(&a[0]+1));

    return 0;
}


//////////////////////////////
///// 指针 +1 运算  ///////////
//////////////////////////////

struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}* p1;

struct Test* p2;

//结构体Test类型的变量大小是 4 + 4 + 2 + 1*2 + 2*4 = 20 个字节
int main()
{
	p1 = (struct Test*)0x100000;
	printf("%p\n", p1 + 0x1); // 0x00100000 + 0x00000014 = 0x00100014, p1是结构体指针，+1跨越20byte
	printf("%p\n", (unsigned long)p1 + 0x1); // 0x00100001
	// 0x00100000 -> 强制转化为无符号长整型 -> 整型提升 -> 0x0000000000100000 + 0x0000000000000001 = 0x0000000000100001 -> %p打印32bit输出 -> 整型截断 -> 0x00100001
	printf("%p\n", (unsigned int*)p1 + 0x1); // 0x100004，unsigned int* 指针+1，跨越4个字节

	return 0;
}


/////////////////////////////////
//// 二维数组的数组指针应用///////
/////////////////////////////////

int main()
{
	int a[5][5];
	int(*p)[4];  // p的数据类型为：int(*)[4]
	p = a;   // 二维数组的数组名是以该行数组的首元素地址表示的第一行一维数组的数组地址，a的数据类型为：int (*) [5], 5是列,  p = a;语句会报警告，但是仍然会将 a 的第一行数组地址传给 p
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]); 
    // a 和 p 的数组地址 起始一致，p[4][2] == *(*(p+4)+2) *(p+4)拿到第5行的数组名，数组名即为首元素地址，+2 拿到当前行的第3个元素地址，最终解引用操作拿到5行3列的元素
                              // a[4][2] == *(*(a+4)+2) a+1 移动一个数组即 5 个int元素，p+1 移动一个数组即 4 个int元素

	return 0;
}


int main()
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* ptr1 = (int*)(&aa + 1); // &aa 二维数组的地址，&aa+1跨过整个数组，移到数组最后一个元素后一个的元素的地址
	int* ptr2 = (int*)(*(aa + 1)); // aa数组名表示首元素地址，也是第一行的数组地址，aa+1 移动到第二行拿到第二行的数组地址，*(aa+1) 拿到第二行的数组名aa[1]
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1)); // 10, 5

	return 0;
}