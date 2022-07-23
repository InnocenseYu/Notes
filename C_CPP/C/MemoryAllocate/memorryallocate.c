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



////////////////////////////////////////////
////// 返回栈空间地址问题 非法访问内存 ////////
////////////////////////////////////////////

char* GetMemory(void)
{
	char p[] = "hello world";
	return p; // 非法访问内存
}

void Test(void)
{
	char* str = NULL;
	str = GetMemory(); // 函数返回的 p指针指向的数组 是栈区开辟的临时变量，函数结束后 p指针代表的数组空间将会被销毁(如果连续两次调用该函数直接没有其他语句执行可能不会被立刻销毁)，
	                   // 这里虽然返回了p，但是对 p指针指向内存操作的内存值将是随机的
	printf(str); // 返回的是一个随机值
}


int* test()
{
    int a = 10; 
    return &a; // 返回 栈区 空间地址，非法访问
}

int* test()
{
    static int a = 10; // 将 a 由栈区 放到 静态区，a的空间在函数调用后不会被释放，仍可使用
    return &a; // 静态区
} 

int* test()
{
    int* ptr = malloc(100); // ptr指针的地址指向 堆区，必须使用 free(ptr) 才可以被释放，否则会内存泄漏，不同于栈区的调用完自动释放
    return ptr; // 堆区
}