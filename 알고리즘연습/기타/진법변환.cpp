/*
 16���� char �� ���� getchar()�� �Է¹޾� �� �ڸ� 10������ ���
 if,while,for,do-while ���� ��� ���Ұ�
 ����� �Լ��� �ݵ�� getchar(), putchar() �� �ؾ���

 �Է� : AB  ��� : 171
 �Է� : 00  ��� : 000
*/

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
	char a[2];
	a[0] = getchar();
	a[1] = getchar();
	char* stop;
	long n = strtol(a, &stop, 16);
	char one, two, three;
	one = n / 100 + '0';
	two = (n % 100) / 10 + '0';
	three = (n % 100) % 10 + '0';
	putchar(one);
	putchar(two);
	putchar(three);
}