//ģ���û���¼�龰,ֻ�ܵ�½����(ֻ��������,��ȷ�ĵ�¼�ɹ�,����ʧ��)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int i = 0;
	for (; i < 3; ++i) {
		printf("��������������:");
		char password[10] = { 0 };
		scanf("%s", password);
		//c������,�Ƚ��ַ����Ƿ����,����ֱ��==,����ʹ�� strcmp ����
	    //strcmp ����0��ʱ���ʾ�����ַ������*/
		if (strcmp(password, "123456") == 0) {
			break;
		}
	}
	//���������������ȷ���µ�ѭ������, ��������3�δ����µ�ѭ������
	if(i < 3) {
		printf("��������������ȷ,��½�ɹ�\n");
	}
	else {
		printf("���������������,��½ʧ��\n");
	}
	system("pause");
	return 0;
}