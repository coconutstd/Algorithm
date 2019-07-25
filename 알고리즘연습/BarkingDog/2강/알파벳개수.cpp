#include <cstdio>
int arr[26];
int main() {
	char x;
	while (true) {
		scanf("%c", &x);
		if (x == '\n') {
			break;
		}
		arr[x - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", arr[i]);
	}
}