#include<stdio.h>
#include<stdlib.h>

// 栈区越址访问
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

///////////////////////////////
/////字符串内容复制函数优化//////
///////////////////////////////

// strcpy 系统库函数，需包含 #include <string.h>
//字符串拷贝
char* strcpy(char* destination, const char* source);

//优化前代码
void my_strcpy(char* dest, char* src)
{
	while(*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = *src; //copy '\0'
} 

//代码优化1
void my_strcpy(char* dest, char* src)
{
	while(*src != '\0')	  
	{
		*dest++ = *src++;
	}
	*dest = *src;
}


//代码优化2
void my_strcpy(char* dest, char* src)
{
	while(*dest++ = *src++)  //while判断条件为：*src赋值到*dest后的内容是否为真，真的话执行{}, 
	                         //字符串*src最后一次将未显示的字符'\0'赋值给*dest,此时*dest值非真，跳出循环
							 //可以完成'\0'的赋值
	{
		;
	}
}


//代码优化3   //当是NULL时，程序不进行赋值拷贝，正常执行，不至于程序崩溃产生影响
void my_strcpy(char* dest, char* src)
{
	if(src != NULL & dest != NULL) //逻辑与 还是 位与
	while (*dest++ = *src++)
	{
		;
	}
}	

//代码优化4    //assert() 断言函数的使用，
void my_strcpy(char* dest, char* src)
{
	assert(src != NULL);//断言，必须引用头文件 #include <assert.h>
	assert(dest != NULL);

	while (*dest++ = *src++)
	{
	 	;
	}
}
 

//代码优化5  //const 修饰*src，防止src、dest两个地址前后位置调换出现错误
void my_strcpy(char* dest, const char* src)
{
	assert(src != NULL);//断言，必须引用头文件 #include <assert.h>
	assert(dest != NULL);

	while (*dest++ = *src++)
	{
	 	;
	}
}


//代码优化6  //修改void 为 char* ,给定函数返回值，可以直接作为参数被其他函数调用使用，简称：链式访问，函数内部 return 操作
char* my_strcpy(char* dest, const char* src) //const 修饰*src，防止src、dest两个地址因前后位置调换*src被操作，进而出现错误
{
	char* ret = dest;     //数组起始地址保存
	assert(src != NULL);  //断言，必须引用头文件 #include <assert.h>，防止野指针、空指针的危害
	assert(dest != NULL);

	while (*dest++ = *src++) //while判断条件为：*src赋值到*dest后的内容是否为真，真的话执行{}
	{
	 	;
	}
	return ret; //不写成return dest; 因为此时dest地址已经指向字符数组末尾地址，并不能代表数组地址
}


/////////////////////////
///////