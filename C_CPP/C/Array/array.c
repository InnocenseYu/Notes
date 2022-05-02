#include <stdio.h>
#include <stdlib.h>

//数组名是什么？
int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	printf("%p\n",arr);
    printf("%p\n",&arr[0]); //以上两个打印相同
    printf("%d\n",*arr); //0

    char* p = "hello bit.";
    printf( "%s\n", p);

	return 0;
}


//数组应用：冒泡排序，比较相邻两个元素的大小，交换。
void bubble_sort(int arr[], int sz)
{
	
    // int sz = sizeof(arr) / sizeof(arr[0]);  //实际上传递过去的是数组 arr 首元素的地址 &arr [0], 则sz在sizeof函数的作用下sz=4Byte/4Byte
    // 确定冒泡排序的趟数
 	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;// 假设这一趟要排序的数据已经有序
		// 每一趟冒泡排序
		int j = 0;
    	for (j = 0; j < sz-1-i; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;

			    flag = 0;// 本趟排序的数据其实不完全有序
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}
int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	// 对 arr 进行排序，排成升序
	//arr 是数组，我们对数组 arr 进行传参，实际上传递过去的是数组 arr 首元素的地址 &arr [0]
	bubble_sort (arr, sz);// 冒泡排序函数
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}



int TwoDim_arr(int arr)
{
    int arr[3][4] = {1,2,3,4,5};       // 二维数组 3行4列，一行4个元素，默认从左到右、从上到下对{}中元素进行排列，不足的部分默认填充为0；
    int arr1[3][4] = {{1,2,3},{4,5}};  // 第一行4个元素为：1，2，3，0；第二行4个元素为：4，5，0，0；第三行4个元素为：0，0，0，0；
    int arr2[][4] = {{1,2,3},{4,5}};    // 二维数组的列不能省略

    int i=0;
    for(i=0; i<3; i++)
    {
        int j=0;
        for(j=0; j<4; j++)
        {
            printf("%d",arr[i][j]);
            //printf("&arr[%d][%d] = %p\n",i,j,&arr[i][j]); //可以使用%p输出arr[i][j]的内存地址，得到数组中元素是依次存放的；
        }
        printf("\n"); 
    }

    return 0;

}

int main()
{
    //数组的创建与初始化
    int arr[10]={1,2,3}; //不完全初始化，数组前三个初始化为1，2，3，未初始化的元素默认为0；
    //字符数组初始化：
    char arr_char[5] = {'a','b'}; //不完全初始化，前两个为'a','b'，未初始化的部分默认为0；
    char arr_char1[5] = {'a',98}; //不完全初始化，数组中前两个元素为'a','b'，字符类型在电脑中是以ASCII值存储的，b的ASCII为98，未初始化的部分为0
    char arr_char2[5] = "ab";     //真正放到数组中的元素有三个，分别为'a','b','\0'，未初始化的部分为0
    char arr_char3[] = "abcd";     //指定数组大小的常量在初始化时可以空着，但是定义时不行,数组大小系统可以自动识别；

    int len = sizeof(arr)/sizeof(arr[0]);
    int char_len = strlen(arr_char3);

    int i=0;
    for(i=0;i<len;i++)
    {
        printf("%d\n",arr[i]);
    }

    printf("%d\n",sizeof(arr_char3)); //输出5
    printf("%d\n",strlen(arr_char3)); //输出4

    return 0;
}