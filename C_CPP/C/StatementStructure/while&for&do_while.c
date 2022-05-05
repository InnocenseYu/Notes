#include <stdio.h>

int main()
{
    int n = 0;
    while(i<10)
    {
        //n++; 放到此处时，输出0 1 2 3 4 6 7 8 9 10，排除5
        if(5 == n)
            continue;
        printf("%d ",n); //输出0 1 2 3 4 在5死循环，因为n==5时，返回循环，判断为真，继续执行continue
        n++;
    }
}


int main()
{
	/*
    int ch = getchar();
	putchar(ch);              //putchar printf 每次只能输出一个int 型字符
	printf("%c", ch);
    */

	int ch = 0;
	while ((ch = getchar()) != EOF)  // EOF: end of file，可以使用键盘ctrl + z输入
		putchar(ch);

	return 0;

}

int main()
{
    char password[20] = NULL;
}