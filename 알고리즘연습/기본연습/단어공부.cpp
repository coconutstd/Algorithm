/*
알파벳 대소문자로 된 단어가 주어지면, 
이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 
단, 대문자와 소문자를 구분하지 않는다.
*/

/*
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 
주어지는 단어의 길이는 1,000,000을 넘지 않는다.
*/

//대문자 65 -90 소문자 97-122

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