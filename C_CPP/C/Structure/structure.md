## 结构体

### 使用结构体关键字声明一个 结构名 类型的结构体：
- struct 标记 / 结构名 { };
  - struct 结构体关键字
  - 声明的结构体只是一个描述文件，不会开辟内存空间，只要使用成员变量时才会开辟内存空间
  - 声明结构
  - 结构体是一些值的集合，这些值称为成员变量
  - {}中存放 成员变量，结构的成员变量可以是标量、数组、指针，甚至是其他结构体
  - 可以多次使用标记定义 结构变量

### 使用结构体声明 定义结构变量
- struct 标记 / 结构名 { } 结构变量；
  - 声明结构 和 定义结构变量 一起使用
  - 此时 结构变量 是全局变量

```C

struct Stu //struct 结构体关键字；Stu 标记 / 结构名; struct Stu 结构体类型
{
    //成员变量
    char name[20];
    int age;
    char sex;
    char ID[19];
}s1, s2, s3; //该处的s1 s2 s3 是全局变量，编程应该尽量避免使用全局变量

struct Stu s4; // 使用Stu 结构体类型创建的 全局结构变量 s4;

int main()
{
    struct Stu s5; // s5 是使用Stu 结构创建的 局部结构体变量
}

```

### 定义结构变量不使用 标记 / 结构名 (匿名结构体类型)
- struct {} 结构变量;
  - 当声明结构 和 定义结构变量 合并一起的话，可以不需要使用标记 / 结构名
  - 因为无 标记 / 结构名，所以只能在定义结构体时定义一次全局结构变量
```C

struct
{
    char name[20];
    int age;
    char sex;
    char ID[19];
}s1; // 定义全局结构体变量s1, 因为没有标记名，该结构体变量只能在声明时定义

struct
{
    char name[20];
    int age;
    char sex;
    char ID[19];
}* s2; // 创建结构体指针变量 s2

s2 = &s1 // 可以这样赋值吗？不行，因为编译器 认为 s2 的类型和 &s1 的类型不一致

```

### 直接使用 标记名 定义 结构变量
- struct 标记 / 结构名 结构变量;
- 此时 结构变量 是局部变量

### 结构体的自引用
- 在结构中包含一个类型为该结构本身的成员

```C

struct Node
{

  int data;
  //struct Node next; // 错误定义，类似递归的方式，造成栈溢出
  struct Node* next; // 解决方法

};

// 匿名结构体的 typedef 别名
typedef struct
{
  int data;
  N                                           ode* next; // 错误定义，无标记名 的匿名结构体 typedef 别名，当前使用的别名 Node 仍未定义就拿来使用
}Node;

//解决方案：
typedef struct Node  // 标记名不省略
{                                                                                                                                                    
  int data;
  struct Node* next; // 完整定义 Node 结构体指针
}Node;

```

### 结构体初始化

- 使用结构体定义结构变量时，使用 {} 赋值初始化
  - struct 标记 / 结构名 结构变量 = { };

- 定义时，直接初始化

```C

struct S
{
	int a;
	char c;
	char arr[20];
	double d;
}s1;

struct T
{
	char ch[10];
	struct S s; // 结构体中定义 结构体
  struct T* next; // 结构体的自引用
	char* p;
}t1= {"haha", {10, 'z', "nihao", 6.18}, NULL, "hehe"};

char arr[] = "hello bit\n";
struct T t = { "hehe", {100, 'w', "hello world", 3.14}, NULL, arr}; // 定义时，直接初始化
struct T t2 = {0}; // 将 t2 结构体变量 中成员变量全部初始化为0；

```

- 定义时，直接初始化，乱序赋值

```C

struct S s2 = {
	.d = 3.14159,
	.a = -10,
	.c = 'A',
	.arr = "nihao"
	}; // 定义时，乱序初始化

```

- 定义后，单独对结构变量进行赋值

```C

  s1.a = 5;
	s1.d = 3.1415;
	strcpy(s1.arr, "niyehao"); // 字符数组不接受直接将值赋值给它，它的值是初始化来的
	s1.c = 'B';

// 以下赋值方式对不对？不对，比如s1->a = 5; = 左边为指向a的指针，= 右边为 int 型 两边无法赋值
  // s1->a = 5;
	// s1->d = 3.1415;
	// strcpy(s1->arr, "niyehao"); // 字符数组不接受直接将值赋值给它，它的值是初始化来的
	// s1->c = 'B';


```

```C
// 结构体初始化 //

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
	struct T t = { "hehe", {100, 'w', "hello world", 3.14}, arr }; // 定义时直接初始化时，使用{}包裹，结构体中 结构体初始化仍然使用{}包裹

    print1(t);
    print2(&t);

	// printf("%s\n", t.ch);  // hehe
	// printf("%s\n", t.s.arr); // hello world
	// printf("%lf\n", t.s.d); // 3.14
	// printf("%s", t.p); // hello bit，换行 
	 
	return 0;
}
```

### 结构变量成员操作

- 结构体变量 sb. 成员 访问结构体内部变量
- 结构体指针变量 sp-> 成员 访问结构体内部变量
  - 对成员是 "" 包裹、字符数组类型，使用 strspy() 函数操作，不能类似其他数组使用下标操作

```C

  s1.a = 5;
	s1.d = 3.1415;
	strcpy(s1.arr, "niyehao"); // 字符数组不接受直接将值赋值给它，它的值是初始化来的
	s1.c = 'B';

// 以下赋值方式对不对？不对，比如s1->a = 5; = 左边为指向a的指针，= 右边为 int 型 两边无法赋值
  // s1->a = 5;
	// s1->d = 3.1415;
	// strcpy(s1->arr, "niyehao"); // 字符数组不接受直接将值赋值给它，它的值是初始化来的
	// s1->c = 'B';


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


```

### 结构体内存对齐

- 原因：结构体的内存对齐是拿空间来换取时间的做法
  - 32bit机器 有32根地址线即32根数据线，所以一次拿 4byte, 如果不是按照每次拿 4byte 来计算的话，则至少需要2次来寻找数据
- 内存分布情况：
  - 第一个结构体变量成员 在结构体变量地址 偏移量为0 的地址处
  - 其他结构体变量成员 要对齐到 对齐数 的整数倍的地址处(地址从上一个结构体成员地址起始端开始的)
    - 对齐数：编译器默认的一个对齐数 与 该变量成员大小 的较小值, min(默认对齐数，结构体变量成员大小（byte）)
      - vs 平台默认值为 8byte
      - gcc 平台无默认值，以结构体变量成员大小（byte）为准
  - 结构体 总大小为 除第一个结构体变量成员 外 其他结构体变量成员 的 最大对齐数的整数倍
  - 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍

![](../Structure/struct_memory.png)


```C

struct S
{
  char c1; // c1与s1 偏移量0的地址一致
  int a; // a 大小为4byte, 对齐数 = min(8,4) = 4，偏移地址：对齐数4*1=4，上一个结构体成员 c1 起始端地址 1 + 3个字节 = 对齐数4，补三个字节空间处存储 a 4个字节
  char c2; // c2的大小为 1byte, 对齐数为min(8,1) =1, 偏移地址：对齐数1*1 =1，从上一个结构体成员 a 的末端地址 顺接即可
  // 结构体大小：max(a对齐数4，c2对齐数1) = 4，当前为 9byte, 4*2 < 9byte < 4*3, 所以末端补3，以满足 vs平台 默认对齐数 8 的整数倍要求，结构体大小为 4*3 =12

};

struct S s1={0};

// 例题1
struct S3
{
double d;
char c;
int i;
};
printf("%d\n", sizeof(struct S3)); // 8 + 1 + 3 + 4 = 16 byte 


```


### 定义结构体指针

- struct 标记 / 结构名* 结构变量;
  - 定义结构体指针，结构变量自身类型为 struct 标记 / 结构名*，指针指向类型为 struct 标记 / 结构名

```C

// 定义结构变量指针//
struct Stu*
{
    char name[20];
    short age;
    char sex;
    char phone[12];
}s1; //使用结构体定义结构变量指针 s1

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
	struct T t = { "hehe", {100, 'w', "hello world", 3.14}, arr }; // 结构体初始化时，使用{}包裹，结构体中 结构体初始化仍然使用{}包裹
  
  print2(&t);

	return 0;
}

```

### 结构体传参
- 结构体传参，形参 是对传入 实参结构变量数据 的一份临时拷贝
- 结构体 传地址，通过传入实参的 地址 操作 实参结构变量数据，不会形成数据的临时拷贝，开辟内存空间
- 推荐结构体传参 使用结构体地址

### typedef-类型重定义
- 为某一类型重命名
- typedef 的解释由编译器做出，不同于define的定义是预处理器执行
  - #define 3.14 Pi 
- typedef 定义 符号名称的对象 仅限于类型，无法操作数值
  - typedef unsigned char u8; 正确
  - typedef 8 eight; 错误
- 使用 typedef 命名结构体类型时，可以[省去标记名](#定义结构变量不使用-标记--结构名)
- 使用 typedef 重命名，并不是创建新的类型，它只是创建了一个便于使用的标签
- 使用 typedef 重定义的结构体在使用 标签定义结构变量 的同时，也可以使用 结构体标记 来定于结构变量。

```C
typedef struct Stu
{
    char name[20];
    short age;
    char sex;
    char phone[12];
}Stu; // 使用 typedef 类型重定义 定义的 结构体标签 Stu
      // Stu 相当于：
      // struct Stu
      // {
      //    char name[20];
      //    int age;
      //    char sex;
      //    char ID[19];
      // }

struct Stu
{
    char name[20];
    short age;
    char sex;
    char phone[12];
}s1; //使用结构体定义结构变量s1

// 定义结构变量指针//
struct Stu*
{
    char name[20];
    short age;
    char sex;
    char phone[12];
}s1; //使用结构体定义结构变量指针 s1

int main()
{
    struct Stu s; // 使用结构体标记 struct Stu 定义结构变量
    Stu s1; // 使用 typedef 类型重定义的标签 Stu 来定义变量 s1
            
    struct Stu* s; // 使用结构体标记 struct Stu* 定义结构变量指针
    Stu* s1; // 使用 typedef 类型重定义的标签 Stu 来定义指针变量 s1

            // 即使结构体被 typedef 重定义了也可使用结构体标记来
            // 定于结构变量 
}
```