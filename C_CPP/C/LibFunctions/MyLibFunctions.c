//#include<stdio.h>
//#include <assert.h>

int strlen(const char* str)
// 方法1
int my_strlen(const char* str)
{
	assert(str != NULL)
	
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}

	return end - start;
}

//方法二
// int my_strlen(char* str) 
// {
//    char* end = str;
//    for( ; *end != '\0'; ++end)  //注意此for循环的写法，初值、操作内容没写也要用;表示
//       ;
//    return end - str;
// }

//方法三
// int my_strlen(const char* str）
// {
// 	assert(str != NULL);
	
// 	int count = 0;
// 	while (*str)
// 	{
// 		count++;
// 		str++;
// 	}

// 	return count;
// }


char* strcpy(char* destination, const char* source)
// strcpy 系统库函数，需包含 #include <string.h>
//字符串拷贝
//原代码
// void my_strcpy(char* dest, char* src)
// {
// 	while(*src != '\0')
// 	{
// 		*dest = *src;
// 		src++;
// 		dest++;
// 	}
// 	*dest = *src; //copy '\0'
// } 

    //代码优化1
//void my_strcpy(char* dest, char* src)
//{
	// while(*src != '\0')	  
	// {
	// 	*dest++ = *src++;
	// }
	// *dest = *src;
//}


	//代码优化2
//void my_strcpy(char* dest, char* src)
//{
	// while(*dest++ = *src++)  //while判断条件为：*src赋值到*dest后的内容是否为真，真的话执行{}
	// {
	// 	;
	// }
//}


	//代码优化3   //当是NULL时，程序不进行赋值拷贝，正常执行，不至于程序崩溃产生影响
//void my_strcpy(char* dest, char* src)
//{
	// if(src != NULL & dest != NULL)
	// while (*dest++ = *src++)
	// {
	// 	;
	// }
//}	

	//代码优化4    //assert() 断言函数的使用，
// void my_strcpy(char* dest, char* src)
// {
// 	assert(src != NULL);//断言，必须引用头文件 #include <assert.h>
// 	assert(dest != NULL);

// 	while (*dest++ = *src++)
// 	{
// 	 	;
// 	}
// }
 

//代码优化5  //const 修饰*src，防止src、dest两个地址前后位置调换出现错误
// void my_strcpy(char* dest, const char* src)
// {
// 	assert(src != NULL);//断言，必须引用头文件 #include <assert.h>
// 	assert(dest != NULL);

// 	while (*dest++ = *src++)
// 	{
// 	 	;
// 	}
// }


//代码优化6  //修改void 为 char* ,函数内部return 函数地址，给定函数返回值，可以直接作为参数被其他函数调用使用，简称：链式访问
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