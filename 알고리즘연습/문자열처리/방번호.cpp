#include <iostream>
#include <limits>
using namespace std;
int a[10];

int main() {
	int s;
	scanf_s_s("%d", &s);
	int div = s, mod = 0;
	while (1) {
		mod = div % 10;
		div /= 10;
		a[mod]++;
		if (div == 0) break;
	}
	int max = numeric_limits<int>::min();
	for (int i = 0; i < 10; i++) {
		if (a[i] > max) {
			if (i == 6 || i == 9) {
				int div = (a[6] + a[9]) / 2;
				if ((a[6] + a[9]) % 2 != 0) {
					div++;
				}
				max = div; continue;
			}
			max = a[i];
		}
	}

	printf("%d\n", max);

}