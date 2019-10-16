#include <cstdio>

int main() {
	int x[3], y[3];
	for (int i = 0; i < 3; i++) {
		scanf_s_s("%d %d", &x[i], &y[i]);
	}
	int n_x, n_y;
	if (x[0] == x[1]) {
		n_x = x[2];
	}
	else {
		if (x[1] == x[2]) {
			n_x = x[0];
		}
		else {
			n_x = x[1];
		}
	}
	if (y[0] == y[1]) {
		n_y = y[2];
	}
	else {
		if (y[1] == y[2]) {
			n_y = y[0];
		}
		else {
			n_y = y[1];
		}
	}
	printf("%d %d", n_x, n_y);
}