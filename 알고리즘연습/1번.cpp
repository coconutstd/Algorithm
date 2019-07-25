#include <iostream>
#include <math.h>

using namespace std;

int main(void) {
	long long int N;
	scanf("%lld", &N);
	int a = sqrt((double)N);
	for (int i = a; i >= 1; i--) {
		if (N % i == 0) {
			printf("%lld\n", abs(N / i - i));
			break;
		}
	}
}