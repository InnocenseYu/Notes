////////////////
/// 结构体定义 //
////////////////
struct Book
{
	char name[30];
	short price;
};

// 声明结构 + 定义结构变量一起，带有标记名可以多次使用该结构
struct Book
{
	char name[30];
	short price;
}b1;

// 声明结构 和 定义结构变量 合并一起，可以不需要使用标记 / 结构名，但是只能定义一次结构变量
struct
{
	char name[30];
	short price;
}b1;


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


////////////////////
// 结构体初始化 /////
////////////////////

struct S
{
	int a;
	char c;
	char arr[20];
	double d;
};

struct T
{
	char ch[10];
	struct S s; // 结构体中定义 结构体
	char* p;
};

void print1(struct T tmp) // 结构体传参，tmp 是对传参变量数据的一份临时拷贝。
{
    printf("%s\n", tmp.ch);  // hehe
	printf("%s\n", tmp.s.arr); // hello world
	printf("%lf\n", tmp.s.d); // 3.14
	printf("%s", tmp.p); // hello bit，换行
}

void print2(struct T* tmp) // 结构体 传地址
{
	printf("%s\n", tmp->ch);  // hehe
	printf("%s\n", tmp->s.arr); // hello world
	printf("%lf\n", tmp->s.d); // 3.14
	printf("%s", tmp->p); // hello bit，换行
}

int main()
{
	char arr[] = "hello bit\n"; // hello bit 换行
	struct T t = { "hehe", {100, 'w', "hello world", 3.14}, arr }; // 初始化时，使用{}包裹，结构体中 结构体初始化仍然使用{}包裹

    print1(t);
    print2(&t);

	// printf("%s\n", t.ch);  // hehe
	// printf("%s\n", t.s.arr); // hello world
	// printf("%lf\n", t.s.d); // 3.14
	// printf("%s", t.p); // hello bit，换行 
	 
	return 0;
}
