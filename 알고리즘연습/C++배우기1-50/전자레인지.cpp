#include <cstdio>

int main() {
	int t;
	scanf_s_s("%d", &t);
	int f_m = 0, o_m= 0 , t_s=0;
	int div;
	div = t / 300;
	if (div != 0) {
		f_m = div; t = t - div * 300;
	}
	div = t / 60;
	if (div != 0) {
		o_m = div; t = t - div * 60;
	}
	if (t % 10 != 0) {
		printf("-1\n");
	}
	else {
		printf("%d %d %d\n", f_m, o_m, t / 10);
	}
}