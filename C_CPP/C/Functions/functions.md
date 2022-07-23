## 函数的声明和定义

### 函数的声明
- 在函数声明中，参数的名称parameter1并不重要，只有参数的类型define_type是必需的；
- 函数声明结构: return_type function_name( define_type parameter1, ...);
- 函数的声明一般出现在函数的使用之前。既满足先声明后使用
- 函数的定义是指函数的具体实现，交待函数的一个功能实现
- 函数的声明和定义可以一起设置，也可以先声明，用";"结束，函数定义没有";"

### 函数的定义

```C

//函数定义：区别函数声明

return_type function_name( define_type parameter1, ...)
{
    statement; //语句项
}

// return_type 返回类型
// function_name 函数名
// ()包裹的形参
// define_type 定义类型
// parameter1 函数形式参数1，在函数体中-语句项 中可以直接使用
// ... 其他形参

```
- 工程项目时，函数声明一般放在头文件(.h)中，包含在 main主函数中
- 功能函数单独一个.c文件同main函数放在一起，都位于source文件夹
- C语言自带头文件使用<>包裹；
- 自建头文件使用""包裹；

### 函数头文件
```C
#ifndef __TEST_H__  //main函数使用Add函数时，包含头文件test.h即可 #include "test.h"
#define __TEST_H__

//函数的声明
int Add(int x, int y);

#endif
```

### 函数的参数

```C

//////////////////////////////////////////////////
/// 指针传值 与 传址的区分 动态内存的释放 错误查找 ////
//////////////////////////////////////////////////

void GetMemory(char* p) // 当前是传值调用区别传址调用，p 指针的值是 str 指针值的一份临时拷贝，str 的值并没有改变
{
	p = (char*)malloc(100); // p = NULL; 但是仍然 str = NULL
}

void Test(void)
{
	char* str = NULL;
	GetMemory(str);
	// GetMemory 函数调用后局部变量 p 将销毁，由于 p 指向的 malloc函数开辟的动态内存空间没有被 free(p) 释放，现在 p 又没了，造成动态内存空间无人认领，因此会造成内存泄露；

	strcpy(str, "hello world"); // 该处程序将崩溃，NULL 不是一个有效地址，无法访问；因为 str = NULL; strcpy 函数无法操作字符串到 NULL 空指针

	printf(str); // printf 函数的形参是指针，所以可以直接操作str

}


////// 修改1 //////////////

void GetMemory(char** p)
{
	*p = (char*)malloc(100); 
}

void Test(void)
{
	char* str = NULL;
	GetMemory(&str);
	strcpy(str, "hello world");
	printf(str);

	free(str);
	str = NULL;
}


////// 修改2 /////////

char* GetMemory(char* p)
{
	p = (char*)malloc(100);
	return p;

}

void Test(void)
{
	char* str = NULL;
	str = GetMemory(str);
	strcpy(str, "hello world");
	printf(str);

	free(str);
	str = NULL;
}

```

[数组或者指针作为函数参数](../Array/array.md/#数组作为函数参数)

- 实参：
  - 真实传给函数的参数，叫实参
  - 实参可以是：常量、变量、表达式、函数等。
  - 无论实参是何种类型的量，在进行函数调用时，它们都必须有确定的值，以便把这些值传送给形参
- 形参：
  - 形式参数是指函数名后括号中的变量，因为形式参数只有在函数被调用的过程中才实例化（分配内存单元），所以叫形式参数
  - 形式参数当函数调用完成之后就自动销毁了
  - 因此形式参数只在函数中有效
- 两者关系
  - 当实参传给形参的时，形参其实是实参的一份临时拷贝，对形参的修改是不会改变实参的
  - 数组传参，传递的是一个地址，数组的首地址&arr[0], 对形参的操作实参也会变

### 传值调用
函数的形参和实参分别占有不同内存块，对形参的修改不会影响实参

### 传址调用
- 传址调用是把函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式
- 这种传参方式可以让函数和函数外边的变量建立起正真的联系，也就是函数内部可以直接操作函数外部的变量
  - ![](./function_parameter.png)
  - 调用的函数value_swap中x,y值发生了改变，但是main主函数中a,b值未发生改变，
  - 可以看到main主函数中a值传给x,b值传给y,但是在调用的value_swap函数中只是起到赋值作用并没有操作a,b,
  - 因为地址是唯一的，可以传递地址给value_swap函数，通过地址进行值的操作

### 传值调用和传址调用的选择
- 判断传递给函数的值在函数中是否需要进行值的操作，改变其地址上的值，否则的话传值操作即可

### 函数的嵌套
- 一个函数可以嵌套多个函数，函数和函数之间可以有机的组合


### 链式访问
- 把一个函数的返回值作为另一个函数的参数使用
```C
//例1
char str[] = "abc";
printf("%d\n",strlen(str));
               //3
//例2：
	printf("%d", printf("%d", printf("%d", 43)));
	       //1           //2        //43     
```
