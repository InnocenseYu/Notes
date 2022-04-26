#include<stdio.h>

int my_strlen(char* str)
{
	char* start = str;
	char* end = str;
	while (*end != '\0')
	{
		end++;
	}

	return end - start;
}

int strlen(char* str) 
{
   char* end = str;
   for( ; *end != '\0'; ++end)  //注意此for循环的写法，初值、操作内容没写也要用;表示
      ;
   return end - str;
}