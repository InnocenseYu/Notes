## 动态内存管理与分配


![内存区域划分](../Storage%26Variable/memorry_use.png)


- 动态内存的管理与分配在 堆区 完成，其他两个区为 栈区 静态区
- void* malloc(size_t size);
  - 内存中开辟**size大小字节**的**未初始化**的**连续字节**的空间, 值为随机值
  - 开辟成功的话返回空间的 起始地址，否则返回 NULL，所以**使用时需进行地址检查**


- void* calloc(size_t num, size_t size);
  - 内存中开辟 num 个 size 大小字节的**连续**空间，并初始化为 0
  - 开辟成功的话返回空间的 起始地址，否则返回 NULL，所以**使用时需进行地址检查**


- void\* realloc(void\* ptr, size_t new_size);
  - 当 malloc 或者 calloc 开辟的空间不满足使用时，可以使用 realloc 函数来调整动态开辟的内存
  - ptr 为需要调整空间的动态内存地址，new_size 为调整后新的大小（不是跟ptr指向空间比差额的内存）
  - 注意事项：
    - 如果 ptr 指向的空间之后有足够的内存空间可以追加，则直接追加，后返回 ptr
    - 如果 ptr 指向的空间之后没有足够的内存空间可以追加，则 realloc 函数会重新找一个新的内存区域开辟一块满足需求的空间，并且把原来内存中的数据拷贝回来，释放旧的内存空间并且对指向该空间的指针置NULL，最后返回新开辟的内存空间地址
    - 如果 ptr 指向的空间之后没有足够的内存空间可以追加，在一个新的内存区域也找不到一块满足需求的空间，那么原来旧的内存空间将不会被释放，直接返回NULL
    - 需要使用一个不同于ptr的指针变量来接收 realloc 函数的返回值
    - 必须对返回值进行检查，否则返回 NULL，所以**使用时需进行地址检查**
    - realloc(NULL,40) == malloc(40)

- malloc的执行不需要初始化开辟的空间，所以效率比 calloc 高，是否需要初始化是选择它们的依据
- 当申请的空间不再使用时，malloc calloc realloc 函数申请的空间应该及时释放还给操作系统，遵循谁使用谁释放的原则
  - void free(void* ptr); 
  - free(NULL); 函数什么也不做
  - 只能清除动态开辟的空间
  - 动态空间清除后，虽然 ptr 指针指向的空间被清除，但是 ptr 本身的值并不会改变，所以需要将 ptr 指针的值置为 NULL, 防止被再次乱操作，如再次使用free(ptr)会引起程序崩溃;


```C

int main()
{
	int* sp = (int*)malloc(10 * sizeof(int)); // 开辟 未初始化的 10 个 int 大小的空间, 开辟成功的话返回空间的起始地址，否则返回 NULL
    // int* ptr = (int*)calloc(10, sizeof(int)); // 开辟 10 个 int 大小的空间并初始化为 0，开辟成功的话返回空间的起始地址，否则返回 NULL
    
    int* ptrn = (int*)realloc(sp,20*sizeof(int)); // 将ptr指向的空间10个 int 类型扩展到 20个 int 类型，开辟成功的话返回新空间的起始地址，不成功的化返回 NULL

	if (sp == NULL)
	{
		// 打印错误原因
		printf("%s\n", strerror(errno));
	}
	else
	{
		// 正常使用空间
        for (int i = 0; i < 10; i++)
		    {
			    *(sp + i) = i;
		    }

        if(ptrn != NULL)
        {
            sp=ptrn;

            for (int i = 10; i < 20; i++)
		    {
			    *(sp + i) = i;
		    }

		    for (int i = 0; i < 20; i++)
		    {
			    printf("%d ", *(sp + i)); // 这里 sp 的地址没有发生改变，不同于sp++;
		    }
        }	
	}

	// 当申请的空间不再使用时，应该及时释放还给操作系统，遵循谁使用谁释放原则
	// 清理 sp 指针的值为 NULL;

    free(sp); // 当使用 realloc 函数时，返回值赋值给ptrn, 又有 sp=ptrn; 
              // 所以通过 sp 将 realloc 函数返回到 ptrn 的地址指向的空间释放，这里只需释放 sp 的地址指向空间即可，在realloc 之前产生的 sp 的地址指向空间已经被 realloc 函数释放
	  sp = NULL; // 将 sp 置 NULL，ptrn的值在函数结束时，自动释放


    // free(ptr); // 释放空间后，ptr指向空间的地址不会改变
	  // ptr = NULL;

	return 0;
}

```

### 常见的动态内存错误

- 返回值不检查，对 NULL 解引用 赋值
- 越界访问
- 对非动态开辟内存的free函数使用

  ```C
  void test()
  {
    int a = 10;
    int *p = &a;
    free(p); // 无法释放 a的内存空间，因为 a 不是动态开辟的空间
  }
  ```

- 只释放动态内存的一部分
  
  ```C
  void test()
  {
    int *p = (int *)malloc(100);
    p++;
    free(p);// p 不再指向动态内存的起始位置, 会引起代码奔溃;
  }

- 对同一块动态内存的多次释放
- 解决方法: 紧跟 free（ptr); p = NULL; 可以防止 ptr 指向空间的再次释放，因为 free(NULL) 什么也不会做
  
  ```C
  
  void test()
  {
    int* p= (int*)malloc(10);
    for(int i=0; i<10; i++)
    {
      *(p+i) = i;
    }
    free(p);

    free(p); // 对 p 指针指向内存的多次释放，会引起代码奔溃;

    p = NULL; // 紧跟 free 函数 可以防止 p 指向空间的再次释放，因为 free(NULL) 什么也不会做 
    
  }
  
  ```

- 内存泄漏-动态开辟的内存忘记释放


### 柔性数组

- C99 中，结构体类型中的 最后一个结构成员允许是未知大小的数组，这就叫做**柔性数组**成员

  ```C

  // 示例1
  typedef struct st_type
  {
    int i;

    // 以下是两种创建柔性数组的方式，有些编译器会报错无法编译，可以一种方式不行换成另一个
    int a[0];//柔性数组成员

    int a[];//柔性数组成员

  }type_a;

  ```

  - 结构体中的柔性数组成员前面必须至少一个其他成员；
  - sizeof 返回的这种结构大小不包括柔性数组的内存，sizeof(struct st_type) == 4, a 数组没有大小；
  - 包含柔性数组成员的结构体用 malloc() remalloc() 函数进行内存的动态分配时，分配的内存应该大于结构体的大小，以适应柔性数组的预期大小
    
    ```C
    //////////////////////////
    //// 方法1 //////////////
    ////////////////////////

    //代码1
    type_a *sp = (type_a*)malloc(sizeof(type_a) + 10*sizeof(int));//  40+4 = 44 byte, sizeof(type_a) = 4byte大小是在栈区的空间，10*sizeof(int) = 40在堆区的动态内存空间，预期柔性数组 a 中存放 10个 int 类型元素
    
    if(sp == NULL)
    {
      printf("%s\n", strerror(errno));
    }
    else
    {
      //业务处理
      sp->i = 10;
      for(int i=0; i<10; i++)
      {
        sp->a[i] = i;
      }
    }

    typa_a *sp_re = (type_a*)realloc(sp, 64); // 向 sp 指针指向的空间 重新开辟 64个byte, 扩充了 5 个int 大小的空间

    if(sp_re != NULL)
    {
      sp = sp_re;
      for(int i=10; i<15; i++)
      {
        sp-a[i] = i;
      }
    }

    free(p);
    p = NULL;


    /////////////////////////////
    //// 使用指针 模拟柔性数组 ////
    /////////////////////////////

    struct st_type
    {
      int i; // 4
      int *arr; // 4
    };  // sizeof(struct st_type) == 8byte

    //代码1
    struct st_type *sp = (struct st_type*)malloc(sizeof(struct st_type));
    sp->arr = malloc(10*sizeof(int)); // 栈区开辟的 sp->arr 指针存放 malloc 在堆区开辟的动态内存空间的地址
    
    if(sp->arr == NULL)
    {
      printf("%s\n", strerror(errno));
    }
    else
    {
      //业务处理
      sp->i = 10;
      for(int i=0; i<10; i++)
      {
        sp->a[i] = i;
      }
    }

    typa_a *sp_re = (type_a*)realloc(sp, 64); // 向 sp 指针指向的空间 重新开辟 64个byte, 扩充了 5 个int 大小的空间

    if(sp_re != NULL)
    {
      sp = sp_re;
      for(int i=10; i<15; i++)
      {
        sp-a[i] = i;
      }
    }

    free(p);
    p = NULL;

    ```