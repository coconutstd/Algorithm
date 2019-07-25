#include <iostream>
using namespace std;

int main() {
	int n,min=101,max=-1;

	int sum = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &n);
		if (n < min) min = n;
		if (n > max) max = n;
		sum += n;
	}
	printf("%d\n", sum - min - max);
}