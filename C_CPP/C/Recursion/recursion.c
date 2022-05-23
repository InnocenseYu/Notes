/////////////////////////////////
////////求解字符串长度 函数递归 ////////////////
/////////////////////////////////

int my_strlen(const char* str)
{
	if(str != '\0')
		return 1+my_strlen(str+1);
	else
		return 0;

    // 大事化小原则：
    // my_strlen("hello");
    // 1+my_strlen("ello");
    // 1+1+my_strlen("llo");
    // 1+1+1+my_strlen("lo");
    // 1+1+1+1+my_strlen("o");
    // 1+1+1+1+1+my_strlen("");
    // 1+1+1+1+1+0 = 5

}



int main()
{
    char arr[] = "hello";
    int len = my_strlen(arr);

    printf("len = %d ", len);

    return 0;
}