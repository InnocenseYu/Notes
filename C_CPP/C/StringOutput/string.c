#include <stdio.h>


//字符串数组的不同表达方式
// int main()
// {
// 	char arr[] = "a string";
// 	char arr1[] = { 'a',' ','s','t','r','i','n','g', '\0' };

// 	printf("%s\n", arr);
// 	printf("%s\n", arr1);

// 	return 0;
// }


// 结构体
struct Book
{
	char name[30];
	short price;
};

//声明结构 + 定义结构变量一起，带有标记名可以多次使用该结构
// struct Book
// {
// 	char name[30];
// 	short price;
// }b1;

//声明结构 和 定义结构变量 合并一起，可以不需要使用标记/结构名，但是只能定义一次结构变量
// struct
// {
// 	char name[30];
// 	short price;
// }b1;



int main()
{
	struct Book b1 = {"C Laguage Learning",68}; //使用标记名的结构定义结构变量并且初始化 b1，使用结构体变量 b1.成员 访问内部
	struct Book* pb = b1; //Book标记名的结构定义结构体指针，并且初始化赋值 b1 的地址，使用结构体指针变量pb->成员 访问内部

	//b1.name = "C++"; //这种赋值操作不可执行，不同于使用下标操作的数组，必须使用strcpy函数操作
	strcpy(b1.name,"C++") //使用头文件#include <string.h>
	b1.price = 28;

	printf("书名：%s\n",b1.name);
	printf("价格：%d\n",b1.price);

	printf("书名：%s\n",(*pb).name);  
	printf("价格：%d\n",(*pb).price);  //这种表达可以使用 -> 操作符简化表达

	printf("书名：%s\n",pb->name);  
	printf("价格：%d\n",pb->price);   //等价于上面的表达

	return 0;
}