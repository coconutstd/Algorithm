#include <cstdio>

int cal(int a, int b) {
	int sum = 0,mod=0,div=a;
	while (div != 0) {
		mod = div % b;
		div /= b;
		sum += mod;
	}
	return sum;
}

int main() {
	for (int i = 1000; i <= 9999; i++) {
		if (cal(i, 10) == cal(i, 12) && cal(i, 16) == cal(i, 10)) {
			printf("%d\n", i);
		}
	}
}