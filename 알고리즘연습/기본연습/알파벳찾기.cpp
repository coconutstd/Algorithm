/*
���ĺ� �ҹ��ڷθ� �̷���� �ܾ� S�� �־�����. ������ ���ĺ��� ���ؼ�, 
�ܾ ���ԵǾ� �ִ� ��쿡�� ó�� �����ϴ� ��ġ��, 
���ԵǾ� ���� ���� ��쿡�� -1�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include<iostream>
#include<string>
using namespace std;
int lowerCaseLoc[26];

int main() {
	string S;
	char firstChar = 'a';
	cin >> S;
	for (int i = 0; S[i]; i++) {
		printf("%d ", i);
		int loc = S.find(firstChar);
		if (loc) {
			lowerCaseLoc[i] = loc;
		}
		firstChar += 1;
	}

	printf("\n");

	for (int i = 0; i < 26; i++) {
		printf("%d ", lowerCaseLoc[i]);
	}

	return 0;
}