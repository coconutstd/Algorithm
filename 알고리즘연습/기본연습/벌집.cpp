#include <iostream>
using namespace std;
long long a[20000];
int main() {
	int n;
	scanf("%d", &n);
	a[0] = 1;
	for (int i = 1; i < 20000; i++) {
		a[i] = a[i - 1] + 6 * i;
	}
	for (int i = 0; i < 20000; i++) {
		if (n <= a[i]) {
			printf("%d\n", i + 1);
			break;
		}
	}
}