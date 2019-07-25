#include <cstdio>
#include <algorithm>
using namespace std;


int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a == b && a == c) {
		printf("%d\n", 10000 + a * 1000);
	}
	else if (a == b || b == c || a == c) {
		if (a == b) {
			printf("%d\n", 1000 + a * 100);
		}
		else if (b == c) {
			printf("%d\n", 1000 + b * 100);
		}
		else {
			printf("%d\n", 1000 + c * 100);
		}
	}
	else {
		printf("%d\n", max(a,max(b,c)) * 100);
	}
}