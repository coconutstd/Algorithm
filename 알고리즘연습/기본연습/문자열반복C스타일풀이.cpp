#include<cstdio>
int t, n, i, j;
char d[22];
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %s", &n, d);
		i = 0;
		while (d[i]) {
			for (j = 0; j < n; j++) {
				printf("%c", d[i]);
			}
			i++;
		}
		printf("\n");
	}
}