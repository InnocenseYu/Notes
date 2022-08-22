[toc]

## 程序编译过程

### 翻译环境

- 定义：.c 源文件通过一系列 预处理、编译、链接等操作 生产 .exe (Windows下)可执行程序的过程；

### 运行环境

- 定义：可执行程序运行需要的一系列操作



![image-20220822014825401](image-20220822014825401.png)



#### 编译器

- 组成一个工程程序的每个源文件通过编译过程都会分别转换成目标代码

#### 链接器

- 链接器同时也会引入标准C函数库中**任何被该程序所用到的函数**，而且它可以搜索程序员**个人的程序库**，将其需要的函数也链接到程序中；
- 链接器（linker）将每个目标文件捆绑在一起，结合 标准C函数库 中**任何被该程序所用到的函数**和程序员**个人的程序库**形成一个单一而完整的可执行程序



### 预处理语法

#### 预定义符号

- C 自身内部已经预定义的符号

```C
printf("%s\n", __FILE__); // 当前源文件在系统中的绝对路径地址
printf("%d\n",__LINE__);  // 本段代码所在的行号
printf("%s\n",__DATE__);  // 当前日期 月日年
printf("%s\n",__TIME__);  // 当前时间 时分秒
printf("%s\n",__FUNCTION__);  // 当前 函数名

__STDC__ //如果编译器遵循ANSI C，其值为1，否则未定义
printf("%d\n",__STDC__);
```



### 预处理指令

- #开头的指令都是预处理指令

```c
#define
#include

// 其他
#if
#endif
#ifdef
#line
#pragma pack(4)
#pragma
```



#### #define

- 定义标识符

  - ```c
    #define name stuff // stuff 可以是多种格式
    // #define MAX 100
    // #define STR "haha"
    // #define CASE break;case // 写 CASE 语句的时候自动把 关键字 break带上
    // #define do_forever for(;;)
    
    // 如果定义的 stuff过长，可以分成几行写，除了最后一行外，每行的后面都加一个反斜杠(续行符)。
    // #define DEBUG_PRINT printf("file:%s\t \
                                   line:%d\t \
                                   date:%s\t \
    							   time:%s\n", \
    							   __FILE__,__LINE__, \
    							   __DATE__,__TIME__ )
       
    ```
  
  
  
- 定义宏: 使用宏的变量是对变量的完全替换，应该多使用()
  
	- 宏 **不能出现递归**
  
  - ```c
    #define SQUARE(X) X*X
    SQAURE(5+1); // 11; 
    // 5+1 * 5+1 = 11
    ```
  
    

#### # 和 \## ##

- 如何将参数插入到字符串中？

  - 使用# ，把一个宏参数变成对应的字符串

  - ```c
    #define PRINT(VALUE) printf("the value of " #VALUE "is %d\n", VALUE)
    // #VALUE 相当于把 VALUE 强制变成 "VALUE" 字符串
    // int a = 3,b=4;
    // printf 函数中多个""包裹的字符串天然的会连在一起，当作一个字符串打印
    PRINT(a); // "the value of " "a" "is %d\n"，#VALUE 替换为 "a"，打印为：the value of a is 3
    PRINT(b); // "the value of " "b" "is %d\n"
    ```

- \## 可以把位于它两边的符号合成一个符号

  - 这样的连接必须产生一个合法的标识符。否则其结果就是未定义的

  - ```c
    #define CAT(X,Y) X##Y
    
    int main()
    {
        int nihao = 2022;
        // printf("%d\n",nihao);
        printf("%d\n",CAT(ni,hao));// 打印为2022
    }
    ```

  - 它允许宏定义从分离的文本片段创建标识符

  - ```c
    #define ADD_TO_SUM(num, value) sum##num += value;
    
    ADD_TO_SUM(5,10); // 给 sum5 增加10；
    ```

    

