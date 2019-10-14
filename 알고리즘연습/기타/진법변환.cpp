/*
 16진수 char 두 개를 getchar()로 입력받아 세 자리 10진수로 출력
 if,while,for,do-while 등의 제어문 사용불가
 입출력 함수는 반드시 getchar(), putchar() 로 해야함

 입력 : AB  출력 : 171
 입력 : 00  출력 : 000
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