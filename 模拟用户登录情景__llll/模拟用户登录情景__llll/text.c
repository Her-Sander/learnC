//模拟用户登录情景,只能登陆三次(只允许三次,正确的登录成功,否则失败)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int i = 0;
	for (; i < 3; ++i) {
		printf("请输入您的密码:");
		char password[10] = { 0 };
		scanf("%s", password);
		//c语言中,比较字符串是否相等,不能直接==,必须使用 strcmp 函数
	    //strcmp 返回0的时候表示两个字符串相等*/
		if (strcmp(password, "123456") == 0) {
			break;
		}
	}
	//如何区分是输入正确导致的循坏结束, 还是输入3次错误导致的循环结束
	if(i < 3) {
		printf("您的密码输入正确,登陆成功\n");
	}
	else {
		printf("您的密码输入错误,登陆失败\n");
	}
	system("pause");
	return 0;
}