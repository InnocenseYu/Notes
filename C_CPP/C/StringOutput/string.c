#include <stdio.h>

int main()
{
	char arr[] = "a string";
	char arr1[] = { 'a',' ','s','t','r','i','n','g', '\0' };

	printf("%s\n", arr);
	printf("%s\n", arr1);

	return 0;
}