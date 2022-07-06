## 库函数

### return
- 一个函数中可以有多个 return a; return b; 等等语句，但是只要碰到一个 return 语句，返回其后紧跟的值，整个函数结束
- 多个 return 语句在一个函数中只会执行一次
- 函数返回值类型是 void时，return 后面不能带任何数字或者语句，直接写分号即可，表示含义是 结束当前函数，如 return; 
- return a; 后面只能接一个a，也就是只能返回一个数

### int printf()
- 返回 int 型 输入字符的个数；
- printf("%s", arr), %s输出内容仍然是直到遇到'\0'停止打印
- printf("%s",arr), arr必须是字符串的地址
- printf("%d\n",b), b在内存中的补码作为有符号整型，打印出b的原码展示
```C
	printf("%d", printf("%d", printf("%d", 43)));
	       //1           //2        //43     
```


### scanf("%10s",name)
- name 地址
- 主要用于以某种标准形式输入的混合类型数据的读取和转换
- 更主要是获取单词而不是获取字符串，因为字符串中的单词的间隔（空白字符）将会导致函数的结束；
- 两种方法决定输入的结束，当两种方式都存在时，最先的满足的方法提前终止函数输入
  - 遇到第一个空白字符
  - 制定了字符宽度，比如 %10s,scanf("%10s",name) 将会读入 10 个字符后停止
```C
// 整型数组赋值，依次赋值
int arr[5] = {0};

    int i = 0;
    for (i = 0; i < 3; i++)
    {
        scanf("%d", &arr[i]);

    }

// 字符型数组赋值，获取单词非字符串
char password[20] = {0};
int i = 0;

for(i = 0; i<3; i++)
    {
        printf("input your password:");
        scanf("%s",password); //scanf()函数直接获取单词，
                              //字符串的话可能因为空格问题导致获取失败
                
    }
```

### gets(name)
- name 指针类型
- 结束条件
  - 直到遇到一个换行字符 "\n" 就会结束，enter 回车键可以产生这个字符
  - 不同于scanf函数，遇到空格或者有字符宽度的输入限制

### sizeof(name)
- 计算变量、数组、类型的大小，单位是字节，是一种 [运算符](../Operator/operators.md);
- 返回类型是 size_t，重定义的 unsigned integer 无符号 int;
```C
// 示例1
  int i; //全局变不初始化-默认是 0
  int main()
  {
    i--;
    if(i>sizeof(i))    // i = -1 有符号整型；
                       // i > sizeof(i)  // int -> unsigned int 
                       // i = -1, 内存中操作的补码为：
                       // 10000000000000000000000000000001(原)
                       // 11111111111111111111111111111110(反)
                       // 11111111111111111111111111111111(补)
                       // int -> unsigned int, 补码的符号位 1 不是符号位，当作值来对待，且是正数，正数 原码 = 补码 
                       // sizeof(i) 返回 size_t(typedef) -> unsigned int
                       // sizeof(i) = 4, 00000000000000000000000000000100
                       // i > sizeof(i); 11111111111111111111111111111111 > 00000000000000000000000000000100  return true;
      printf(">\n“);
    else
      printf("<\n");

    return 0;
  }
```

- 当 name int 型 (4B) 数组, 两个元素时，计算所占空间大小为 4*2=8B;
- 当 name char 型 (1B) 数组, 使用 ""包裹 3 个字符时，所占空间大小为 4*1=4，包括所有未显示的部分末尾处'\0'；
- 区分指针操作中数组名即为首元素的地址，arr 等于 & arr[0];
- sizeof(arr) 不等于 sizeof(&arr[0])，这里 arr 指的是数组的全部存储区空间，&arr[0] 指的是 arr 数组首元素在存储空间的位置
- 类型大小就是该类型创建变量的大小
  - 如 char* a; short* a; double* a; 创建的变量 a 是不同类型的指针变量，存放地址，32 位平台，sizeof(char*) = sizeof(short*) = sizeof(double*) = 4byte；64 位系统大小为 8byte

```C
// 示例2
short s = 0; // short 类型占2个字节
int a = 10;
printf("%d\n", sizeof(s = a + 5)); //2, a + 5的值赋值到 s 类型，其实不会进行运算，sizeof 计算的是s的大小；
printf("%d\n", s); //0
printf("%d\n", sizeof a); //4
printf("%d\n", sizeof(a)); //4
printf("%d\n", sizeof(int)); //4
//printf("%d\n", sizeof int); //err

// 示例3
// 1 2 3 4 四个指示位置分别输出多少
void test1(int arr[])
{
  printf("%d\n", sizeof(arr));  //1 形参传递的是地址， 32bit平台， 地址 4byte 输出4
}

void test2(char ch[])
{
  printf("%d\n", sizeof(ch));  //2 形参传递的是地址， 32bit平台， 地址 4byte 输出4
}

int main()
{
  int arr[10] = {0};
  char ch[10] = {0};
  printf("%d\n", sizeof(arr));   //3 输出4 * 10 = 40
  printf("%d\n", sizeof(ch));    //4 输出1 * 10 = 10
  test1(arr);
  test2(ch);

  return 0;
}

```

### strlen(name)
- strlen 函数 求字符串的长度, 只能针对字符串，''包裹的单个字符依次使用, 分隔放在 {} 中的字符串在使用 strlen() 函数时，需要在最后一个字符末尾加个'\0'才能使用
- 直到遇到'\0'停止运行，计算的是'\0'之前可以显示的字符个数

### strcpy(destination,resource)
- "" 包裹的字符串数组必须使用系统函数 strcpy() 进行操作, 使用下标操作数组的方法不适用，函数包含在 string.h 头文件中
- char* strcpy(char* destination, const char* source) ，本文件夹下. c 文件可参考
- 直到遇到'\0'停止运行，复制的是'\0'之前可以显示的字符

### strcmp()
- 比较两个字符串是否相等
- int 型返回
  - 第一个字符串大于第二个字符串，则返回大于 0 的数字
  - 第一个字符串等于第二个字符串，则返回 0
  - 第一个字符串小于第二个字符串，则返回小于 0 的数字
  - 比较的不是字符串的长度，而是对应位置字符中字母的大小，a<b<…<z, 大写同理
```C
等于符号 ==

不能用于字符串比较，char password[20] = {0}; password == "lixinyu"
但是可以用于两个字符数组指针 值 的比较，char* str1[] = NULL; char* str2[] = NULL; *str1 == *str2
```

### int getchar(void)
- 返回 int 型函数
- 输入参数无
- 每次只能接收键盘**一个**输入字符，使用循环语句可以连续输入；
- getchar()
  - 结束标志为关键字 EOF

### putchar(ch)
- 打印 ch 的一个字符
- 同 printf("%c",ch)

### Sleep(m_seconds)
- 按照时间 m_seconds 毫秒 休息一会
- 包含在windows.h头文件中

### system("permanent")
- 执行系统命令给的函数
- 可以写的参数 permanent 有:
  - pause 暂停
  - cls 清空屏幕
  - shutdown -s -t 60 关机 设置 时间 60s 
  - shutdown -a 取消关机

### sqrt(n)
- 对 n 开根号
- 包含头文件 math.h


