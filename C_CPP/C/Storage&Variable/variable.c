#include <stdio.h>

///////////////////////////////
//static、extern 关键字修饰变量 //
///////////////////////////////

// 源文件test.c
#include <stdio.h>

void test()
{
    //int n = 1;  // 局部变量只作用在作用域，用完后释放存储
    static int n = 1;  //static 改变局部变量的作用域
    n++;
    printf("%d\n",n);

}

// 头文件 test.h
void test(void);

// 源文件 main.c
#include <stdio.h>
//void test(); // main.c 未包含 头文件 test.h ，直接这样使用 test() 函数无效；
extern void test();  // 当头文件未包含 test() 函数时，可以使用 extern 关键字引用使用，但 仅仅作用于函数的调用，与调用函数的内部参数无关系

int main()
{
    int i = 0;
    while(i<3)
    {
        test(); // 局部变量 n 只作用在 test() 作用域，用完后释放存储
        i++;
    }

    return 0;
}


///////////////////////////////
/////////大小端的判断 //////////
///////////////////////////////

// 方法1
int check_sys(void)
{
    int a = 1;
    char* p = (char*)&a; // 强制转化为char* 类型，虽然 a 是int 类型，4byte, 但是拿值时是 从低字节开始，1byte的拿

    if(1 == *p)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

// 代码优化1
int check_sys(void)
{
    int a = 1;
    char* p = (char*)&a;
    return *p;
    // 因为
    // if(1 == *p)
    // {
    //     return 1;
    // }
    // else
    // {
    //     return 0;
    // }
    // 所以 return *p即可

}

// 代码优化2
int check_sys(void)
{
    int a = 1;
    return *(char*)&a; // 不使用p作为中转
}


// 方法2
int check_sys(void)
{
    union
    {
        char a;
        int b;
    }u;

    u.b = 1;

    return u.a; // 返回1 即为小端
}


int main()
{
    int ret = check_sys();
    // 返回1 小端模式
    // 返回0 大端模式
	if(1 == ret)
    {
        printf("小端");
    }
    else
    {
        printf("大端");
    }

    return 0;
}


/////////////////////////////
////// 打印结果是多少 ////////
////////////////////////////

int main()
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	// c 二进制 -1
	// 10000000000000000000000000000001 原码
	// 11111111111111111111111111111110 反码
	// 11111111111111111111111111111111 补码
	// 整型截断
	// unsigned char c 11111111
	printf("a=%d,b=%d,c=%d", a, b, c);
	// c = %d
	// 1, 整型提升 unsigned char -> int 
	// 11111111 -> 00000000000000000000000011111111 补码
	// 2, 补码 -> 原码 转换
	// %d 有符号十进制 输出，根据补码的符号位进行 补码 -> 原码 转换，输出原码
	// 因为 00000000000000000000000011111111 补码 最高位符号位为0，正值，补码 = 原码
	// 3, 原码二进制 -> 十进制 
	// 00000000000000000000000011111111 -> 255
	return 0;
}

int main()
{
	char a = -128;
	// a       10000000000000000000000010000000 原码
	//         11111111111111111111111101111111 反码
	//         11111111111111111111111110000000 补码
	// 整型截断 char a  10000000
	printf("%u\n", a);
	// 1, 整型提升 char -> int 
	// 10000000 -> 11111111111111111111111110000000 补码
	// 2, 补码 -> 原码 转换
	// %d 有符号十进制整型 输出，正常是根据补码的符号位进行 补码 -> 原码 转换，输出原码，
	// 但是 %u 无符号十进制整型 输出的话，默认整型提升后的补码最高位不是符号位，是无符号数，原码 反码 补码 三码相同，无需转换
	// 3, 无符号二进制 -> 十进制 
	// 11111111111111111111111110000000 -> 4294967168
	return 0;
}

