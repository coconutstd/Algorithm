#include <cstdio>
#include <math.h>
typedef long long int lld;
int main() {
	lld s;
	scanf("%lld", &s);
	lld d = sqrt(s*2);
	lld sum1 = (d - 1) * d;
	lld sum2 = d * (d + 1);
	if (s*2 >= sum2) {
		printf("%lld\n", d);
	}
	else {
		printf("%lld\n", d-1);
	}
}