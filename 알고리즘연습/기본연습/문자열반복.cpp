/*
���ڿ� S�� �Է¹��� �Ŀ�, �� ���ڸ� R�� �ݺ��� �� ���ڿ� P�� ���� �� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
��, ù ��° ���ڸ� R�� �ݺ��ϰ�, �� ��° ���ڸ� R�� �ݺ��ϴ� ������ P�� ����� �ȴ�. 
S���� QR Code "alphanumeric" ���ڸ� ����ִ�.
QR Code "alphanumeric" ���ڴ� 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: �̴�.
*/

/*
ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1 �� T �� 1,000)�� �־�����. 
�� �׽�Ʈ ���̽��� �ݺ� Ƚ�� R(1 �� R �� 8), 
���ڿ� S�� �������� ���еǾ� �־�����. S�� ���̴� ��� 1�̸�, 20���ڸ� ���� �ʴ´�.
*/

#include <iostream>
#include <string.h>
using namespace std;
int TestCase;
int iter;
char c[100];
string alpha;
string newAlpha;

int main() {
	
	scanf("%d", &TestCase);
	
	while (TestCase--) {
		scanf("%d %s", &iter, c);
		alpha = c;
		for (int i = 0; i < alpha.length(); i++) {
			newAlpha.append(iter, alpha.at(i));
		}
		printf("%s\n", newAlpha.c_str());
		
		strcpy(c, "\0");
		alpha.clear();
		newAlpha.clear();
		
	}
	return 0;
}