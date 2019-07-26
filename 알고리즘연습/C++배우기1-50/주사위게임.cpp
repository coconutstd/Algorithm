#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	int t,m=-1;
	scanf("%d", &t);
	while (t--) {
		int sum = 0;
		scanf("%d %d %d", &a, &b, &c);
		if (a == b && b == c) {
			sum = 10000 + a * 1000;
		}
		else if (a == b || a == c || b == c) {
			if (a == b) {
				sum = 1000 + a * 100;
			}
			else if (a == c) {
				sum = 1000 + a * 100;
			}
			else {
				sum = 1000 + b * 100;
			}
		}
		else {
			sum = max(a, max(b, c)) * 100;
		}
		if (sum > m) m = sum;
	}
	printf("%d\n", m);
}