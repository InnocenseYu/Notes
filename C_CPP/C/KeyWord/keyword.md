## 关键字

### typedef-类型重命名

- 使用方法：
  - typedef 需要定义的类型 类型重定义后的标签（通常）
  - 针对 构造类型，需要具体分析

[typedef 结构体](../Structure/structure.md/#typedef-类型重定义)

#### typedef 类型重命名 常规方式

```C
// 通常 类型在中间，重命名的类型别名 在最后

typedef unsigned int uint;
uint a = 10; 
// 等价于 unsigned int a = 10; 

```

#### typedef 类型重命名 类型别名不在最后

```C
typedef int(ArrayType)[10]; // 优先级 () > [], 类型别名为 ArrayType
ArrayType array = { 0 }; // 与 int array[10] = {0}; 作用相同


typedef int* PointerArray[10]; // 优先级 [] > *, 指针数组类型, 别名为 PointerArray

typedef int(*ArrayPointer)[10]; // 优先级 () > [], 数组指针类型, 别名为 ArrayPointer

// 如何简化如下代码
void (*signal(int, void(*)(int))) (int);
// 1. void (*   signal(int, void(*)(int))   ) (int), 
// signal(int, void(*)(int)) 函数的返回类型是什么？函数形参 void(*)(int) 是什么？
// 返回类型：void(*)(int)；形参是函数指针
typedef void(*FuncPointer)(int); // 函数指针类型，别名为 FuncPointer
// 2. 代码改写
FuncPointer(signal(int, FuncPointer));


```

### define-宏定义 
- #define MAX(X,Y) (X>Y?X:Y)
- 使用 MAX(X,Y) 替换 (X>Y?X:Y)



### NULL-空指针

- NULL 空指针不是一个有效地址，不指向一块有效空间;
  - strcmp(NULL,"abc"); 操作失败
- free(NULL); 不会操作失败，，但是什么也不会做