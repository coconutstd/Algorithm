/*
���ĺ� ��ҹ��ڷ� �� �ܾ �־�����, 
�� �ܾ�� ���� ���� ���� ���ĺ��� �������� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�. 
��, �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.
*/

/*
ù° �ٿ� ���ĺ� ��ҹ��ڷ� �̷���� �ܾ �־�����. 
�־����� �ܾ��� ���̴� 1,000,000�� ���� �ʴ´�.
*/

//�빮�� 65 -90 �ҹ��� 97-122

#include <cstdio>
int arr[26];
char c[1000009];
int i = 0;
int main() {
	scanf("%s", c);
	while (c[i]) {
		if (65 <= c[i] && c[i] <= 90) arr[c[i] - 65] += 1;
		else arr[c[i] - 97] += 1;
		i++;
	}
	
	int location, value = -9999;
	bool isMulti = false;
	for (int j = 0; j < 26; j++) {
		if (arr[j] != 0 && value < arr[j]) {
			location = j;
			value = arr[j];
		}
	}
	for (int j = 0; j < 26; j++) {
		if (j == location) continue;
		else if (value == arr[j]) isMulti = true;
	}

	if (isMulti) printf("%c", '?');
	else printf("%c", location + 65);

}