#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include <string.h>

///////////////////////////
/////字符串长度函数优化//////
///////////////////////////

size_t strlen(const char* str); //size_t 是typedef 重命名的类型 unsigned int
// 方法1
int my_strlen(const char* str)
{
	assert(str != NULL);
	
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}

	return end - start;
}

//方法二
int my_strlen(char* str) 
{
   char* end = str;
   for( ; *end != '\0'; ++end)  //注意此for循环的写法，初值、操作内容没写也要用;表示
      ;
   return end - str;
}

//方法三
int my_strlen(const char* str)
{
	assert(str != NULL);
	
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}

	// while(*str++)
	// 	count++;
	

	return count;
}

//方法四
int my_strlen(const char* str)
{
	if(str != '\0')
		return 1+my_strlen(str+1);
	else
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
	*dest = *src; // 弥补剩下的 '\0'
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
	char* ret = dest;     // 提前保存 dest 字符串的起始地址
	assert(src != NULL);  // 断言，必须引用头文件 #include <assert.h>， 只要 assert 函数内部的**参数表达式返回结果**为**假**，就打印一条出错信息，然后终止程序运行
	                      // 防止野指针、空指针的危害
	assert(dest != NULL);

	// assert(src && dest) // 也可这样使用，一般不建议多个表达式放在一起，因为不易判断是哪个的问题

	while (*dest++ = *src++) //while判断条件为：*src赋值到*dest后的内容是否为真，真的话执行{}
	{
	 	;
	}

	return ret; //为什么不写成return dest？
	// 因为此时dest经过dest++操作，地址已经向后偏移src的strlen+1长度，并不能代表dest的字符地址，需要在操作前提前保存

}


////////////////////////////////
///////my_strcat 字符串 追加 ////
////////////////////////////////

char* my_strcat(char* dst, const char* src)
{
	assert(dst && src); // 排除 dst 和 src 中任一个是空指针 NULL(0)
	
	char* ret = dst;
	
	// 拿到 *dst 中 '\0'的地址  
	while(*dst)
	{
		dst++;
	}

	// while(*dst++);

	// 追加src字符串到dst的尾端(覆盖'\0')
	while(*dst++ = *src++) // *src的'\0'也会被追加过去
	{
		;
	}

	return ret;

}

////////////////////////////////
///////my_strcmp 字符串比较 ////
////////////////////////////////

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);

	while(*str1 == *str2)
	{
		if(*str1 == '\0')
		{
			return 0;
		}

		str1++;
		str2++;
	}

	return (*(unsigned char*)str1 - *(unsigned char*)str2);

}


//////////////////////////
//// 实现my_strncpy //////
/////////////////////////

char* my_strncpy(char* dst, const char* src, unsigned int num)

{
	char* start = dst;

	assert(dst && src);

	//while (*dst++ = *src++) // num > strlen(src)+1, num控制的字符个数数组才会起作用
	//	num--; // 

	//while ((*dst++ = *src++)!= '\0') // num > strlen(src)+1, num控制的字符个数数组才会起作用
	//	num--; 

	while (num && (*dst++ = *src++)!= '\0') // 此时 num 控制的字符个数和 *src 末端 '\0' 同时起作用
		num--; 

	//while (--num) // 当 num = 0时，--num表达式结果为-1 真，所以不合适
	//{
	//	*dst++ = '\0';
	//}
	
	if (num) // 排除num = 0 的影响，因为 0-1 = -1 为真
	{
		while (--num)  // 之所以使用--num 因为src的'\0'在赋值过去时，while(*dst++ = *src++) 中*dst++完成赋值，但是*dst++ = *src++表达式结果为假，num--不会执行，所以 -- 可以使 num 中包含'\0'
			*dst++ = '\0'; // 余下num个字符全部赋值为'\0'
	}

	return(start);
}


/////////////////////////
//// 实现 my_strncat /////
/////////////////////////

char* my_strncat(char* dst, const char* src, unsigned int num)
{
	char* start = dst;

	assert(dst && src);

	while(*dst++) // dst 指向 '\0' 值的后一个地址
		;
	dst--; // 将 dst 地址拉回到 '\0' 值的地址

	// while(num && (*dst++ == *src++)!='\0') // 这样写不合适，因为无论 num > strlen(src) + 1 或者 num < strlen(src) + 1 都需要在增添后的 *dst后添加 '\0', 使之成为完整的字符串
	// 								       // 因此分别操作 num 和 (*dst++ == *src++)!='\0'
	// 									   // num 的操作级别比 (*dst++ == *src++)!='\0' 高，所以优先考虑 num
	// 	num--;

	while(num--)
	{
		if((*dst++ == *src++) =='\0') // *dst后增添 '\0'操作自动完成
			return start; //不考虑 num 是否已经操作完
	}

	// num 字数操作完后 *dst尾端手动增添 '\0'
	*dst = '\0'; //此时 dst 地址已经指向 num+1个数的位置，因此不需要 *dst++

	return start;
	
}


/////////////////////////
//// 实现 my_strstr /////
/////////////////////////

char* my_strstr(const char* dst, const char* src)
{
	assert(dst && src);

	char* s1 = NULL;
	char* s2 = NULL;

	char* cp = (char*)dst; // dst 是 const char* 类型，cp 是 char* 

	if(*src == '\0')
	{
		return dst;
	}

	// if(!*src)  // src 是 NULL, *src == '\0'; !*src 指的就是*src = '\0', !*src != 0 为真
	// {
	// 	return dst;
	// }

	while(cp)
	{
		s1 = cp;
		char* s2 = (char*)src;

		while(*s1 && *s2 && !(*s1-*s2))
		{
			s1++;
			s2++;
		}

		if(*s2) // *src == '\0'; src已经排查完到'\0'，因为while(*s1 && *s2 && !(*s1-*s2))的限制，'\0'之前的字符全部相同且*s1 ！= 0，所以找到dst中与src 所有重复的字符串
		{
			return cp; // 返回 dst 中与 src 重复开始的位置，这是使用 cp 进行的标记，因为 s1 一直在变化 
		}

		if(*s1) // dst 长度小于 src 提前到达 '\0'的地址，从内部 while 跳出，避免下面语句 cp++ 标记符的再次调用这里提前返回
			return NULL;

		cp++;

	}

	return NULL;

}


////////////////////////////////////////
///// memcpy() 非内存重叠的内存拷贝 //////
////////////////////////////////////////

void* my_memcpy(void* dst, const void* src, unsigned int num)
{
	assert(dst && src);

	void* start = dst;

	while (num--) // 不能满足字符串的末尾 '\0' 的复制
	{
		*(char*)dst = *(char*)src; // 强制转换为字节操作
		++(char*)dst;
		++(char*)src;
		// (char*)dst++ // 自加运算符 ++ 优先级高于 类型转换 (type)
	}

	return start;
}


//////////////////////////////////////////////////////
///// memmove() 重叠内存中的两个变量互相转换(移动) //////
//////////////////////////////////////////////////////

void* my_memmove(void* dst, const void* src, unsigned int num) // num 单位为byte, 需要移动字符串src的大小
{
	void* ret = dst;
	while (num--) // num 已经修改
	{
		if (dst < src) // 比较大小跟类型没有关系
		{
			*(char*)dst = *(char*)src;

			++(char*)dst;
			++(char*)src;
		}
		else
		{
			// *((char*)dst + num -1) = *((char*)src+ num-1); // 因为 while(num--) 已经 num-1 了，所以这里的 1 不需要减了
			*((char*)dst + num) = *((char*)src + num);  // (char*)src + num, 字符类型指针 + unsigned int, src++：每次移动一个地址(1byte) +1 这个 1 可以是int 也可以是unsigned int

		}
	}

	return ret;
}


void* my_memset(void* dst, int c, unsigned int num)
{

}