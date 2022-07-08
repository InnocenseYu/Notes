## 结构体

### 定义方式：
- struct 标记 / 结构名 { };
  - 定义的结构体只是一个描述文件，不会开辟内存空间，只要使用成员变量时才会开辟内存空间
  - 声明结构
  - 结构体是一些值的集合，这些值称为成员变量
  - {}中存放 成员变量，结构的成员变量可以是标量、数组、指针，甚至是其他结构体
  - 可以多次使用标记定义 结构变量

### 使用结构体初始定义 定义结构变量
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

int main()
{
    struct Stu s; //s 是使用Stu 结构创建的 局部结构体变量
}
```

### 定义结构变量不使用 标记 / 结构名
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
}s1; // 定义全局结构体变量s1, 因为没有标记名，该结构体只能在定义时 使用一次
```

### 直接使用 标记名 定义 结构变量
- struct 标记 / 结构名 结构变量;
- 此时 结构变量 是局部变量

### 结构体初始化
- 定义时，直接初始化
- 使用结构体定义结构变量时，使用 {} 赋值初始化
  - struct 标记 / 结构名 结构变量 = { };

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
	struct T t = { "hehe", {100, 'w', "hello world", 3.14}, arr }; // 初始化时，使用{}包裹，结构体中 结构体初始化仍然使用{}包裹

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

### 定义结构体指针

- struct 标记 / 结构名* 结构变量;
  - 定义结构体指针，结构变量自身类型为 struct 标记 / 结构名*，指针指向类型为 struct 标记 / 结构名

```C
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