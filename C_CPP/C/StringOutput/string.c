#include <stdio.h>


字符串数组的不同表达方式
int main()
{
	char arr[] = "a string";
	char arr1[] = { 'a',' ','s','t','r','i','n','g', '\0' };

	printf("%s\n", arr);
	printf("%s\n", arr1);

	return 0;
}



//arr = "C++"; //这种赋值操作不可执行，不同于使用下标操作的数组，必须使用strcpy函数操作
//strcpy(arr,"C++") //使用头文件#include <string.h>

