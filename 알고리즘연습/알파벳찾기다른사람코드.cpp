#include<stdio.h>
int main() {
	char a[101], w[26] = {};
	scanf("%s", a);
	for (int i = 0; a[i]; i++) {
		printf("%d ", i);
		if (!w[a[i] - 97])w[a[i] - 97] = i + 1;
	}
	printf("\n");
	for (int i = 0; i < 26; i++)
		printf("%d ", w[i] - 1);
	return 0;
}