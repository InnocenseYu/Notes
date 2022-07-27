#include <stdio.h>
#include <stdlib.h>

// int main()
// {
//     int age = 10;
//     if(age<18)
//     printf("未成年");

//     //if(18<=age<28)  //这个语句错误，因为age>=18为假结果为0，0<28为真，输出青年跟愿意不符
//     else if(age>=18 && age<28)
//         printf("青年"); 
//     else if(age>=28 && age<50)
//         printf("壮年");
//     else //除以上判断外的条件 即age>=50
//         printf("老年");
    

    /////////////////////////////////////
    /// 该写法也是可以的, 注意大括号{}/////
    /////////////////////////////////////

    // if(age<18)
    //     printf("未成年");
    // //if(18<=age<28)  //这个语句错误，因为age>=18为假结果为0，0<28为真，输出青年跟愿意不符
    // else 
    // {
    //     if(age>=18 && age<28)
    //         printf("青年"); 
    //     else if(age>=28 && age<50)
    //         printf("壮年");
    //     else //除以上判断外的条件 即age>=50
    //         printf("老年");
    // }
    

    //////////////////////////////////////////////
    ///以下两个模式模式一正确 悬空 else 跟离他最近的未匹配 if 进行匹配/////
    /////////////////////////////////////////////
    // //模式一
    // int a=0;
    // int b=2;
    // if(a==1)
    //     if(b==2)
    //         printf("hehe\n"); 
    //     else
    //         printf("haha\n");

    // //模式二
    // int a=0;
    // int b=2;
    // if(a==1)
    //     if(b==2)
    //         printf("hehe\n"); 
    // else
    //     printf("haha\n");

    ///////////////////
    ///if(num = 5)中num = 5赋值语句结果是，num = 5 为真，则表达意思不一致，但是没有报错
    ///好的代码风格可以写成：if(5=num)/if(5==num) 首先直接会报错无法通过编译；再次，判断常量和变量相等于时，防止出错
    ////////////////////
    // int num = 4;
    // if(num = 5)
    // printf("hehe\n");

//      return 0;

// }

int main()
{
    int i=1;
    for(i = 1;i<=100;)
    {

        // if(a%2!=0)
        // printf("%d  ", i);

        //算法的益处，相对上个判断，可减少循环次数
        printf("%d  ", i);
        i += 2;
    
    }

    // int i=1;
    // while(i<=100)
    // {
    //     if(i%2 == 1)
    //     printf("%d  ",i)
    //     i++;
    // }



    return 0;
}

/////////////////////////
////switch语句///////////
/////////////////////////
int main()
{
	int n = 0;
	printf("请输入数字n：");
	scanf("%d", &n);
		switch (n)
		{
		case 1:
		case 2:
		case 3:
        case 4:
        case 5:
			printf("工作日\n");
            break;
        case 6:
            printf("星期六\n");
            break;
        case 7:
            printf("星期日\n");

        // 后续添加语句
        // case 8:
        //     printf("不合法输出,请输入1-7数值");
        //     break;
        
        // 最后一个case是否添加break语句
        //如果没有添加后续case时，虽然没有break语句，case 7执行完也会跳出当前switch，
        //但是当在后面加入其他case 时，没有添加break，当输入7会同时执行后续代码，不利于代码的完整性，也不利于别人的参考。
        //建议在switch 中最后一个case添加break语句

        
		}
	return 0;
}
