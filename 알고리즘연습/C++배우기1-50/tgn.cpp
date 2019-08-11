#include <cstdio>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (b - c > a) {
			printf("advertise\n");
		}
		else if (b - c == a) {
			printf("does not matter\n");
		}
		else {
			printf("do not advertise\n");
		}
	}
}