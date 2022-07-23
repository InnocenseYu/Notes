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



