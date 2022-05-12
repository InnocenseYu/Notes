//代码执行逻辑：执行关机程序，打印关机提示，屏幕输入，判断输入的字符串是不是“我是猪”，是的话，取消关机程序，否则返回到 again 标签处，打印，屏幕输入，判断
int main()
{
	char str[20] = { 0 }; 
	system("shutdown -s -t 120");

again:
	printf("电脑将在2分钟关机，请输入：我是猪解除关机\n");

	scanf("%s", str);

	if (0 == strcmp(str, "我是猪"))
		system("shutdown -a");
	else
		goto again;

	return 0;
}

int main()
{
	char str[20] = { 0 };
	system("shutdown -s -t 120");
	printf("系统将在2分钟内关机，请输入：“我是猪”解除\n");
	
	while (1)
	{
		scanf("%s", str);

		if (0 == strcmp(str, "我是猪"))
			goto right;
		else
			printf("不正确，你是猪，请继续输入\n");
	}

right:
	system("shutdown -a");

	return 0;

}