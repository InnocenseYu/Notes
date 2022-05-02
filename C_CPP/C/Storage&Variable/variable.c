#include <stdio.h>

///////////////////////////////
//static、extern 关键字修饰变量 //
///////////////////////////////

// void test()
// {
//     //int n = 1;  // 局部变量只作用在作用域，用完后释放存储
//     static int n = 1;  //static 改变局部变量的作用域
//     n++;
//     printf("%d\n",n);

// }

// //void test(); // 因为头文件未包含，直接这样使用的无效；
// extern void test();  // 当头文件未包含 test() 函数时，可以使用 extern 关键字引用使用，但 仅仅作用于函数的调用，与调用函数的内部参数无关系

// int main()
// {
//     int i = 0;
//     while(i<3)
//     {
//         test(); // 局部变量 n 只作用在 test() 作用域，用完后释放存储
//         i++;
//     }

//     return 0;
// }


////////////////
/// 结构体定义 //
////////////////
struct Book
{
	char name[30];
	short price;
};

// 声明结构 + 定义结构变量一起，带有标记名可以多次使用该结构
// struct Book
// {
// 	char name[30];
// 	short price;
// }b1;

// 声明结构 和 定义结构变量 合并一起，可以不需要使用标记 / 结构名，但是只能定义一次结构变量
// struct
// {
// 	char name[30];
// 	short price;
// }b1;


int main()
{
	struct Book b1 = {"C Laguage Learning",68}; // 使用标记名的结构定义结构变量并且初始化 b1，使用结构体变量 b1. 成员 访问内部
	struct Book* pb = b1; //Book 标记名的结构定义结构体指针，并且初始化赋值 b1 的地址，使用结构体指针变量 pb-> 成员 访问内部

	//b1.name = "C++"; // 这种赋值操作不可执行，不同于使用下标操作的数组，必须使用 strcpy 函数操作
	strcpy(b1.name,"C++") // 使用头文件 #include <string.h>
	b1.price = 28;

	printf("书名：%s\n",b1.name);
	printf("价格：%d\n",b1.price);

	printf("书名：%s\n",(*pb).name);
	printf("价格：%d\n",(*pb).price);  // 这种表达可以使用 -> 操作符简化表达

	printf("书名：%s\n",pb->name);
	printf("价格：%d\n",pb->price);   // 等价于上面的表达

	return 0;
}