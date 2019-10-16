//1000000000000000 999999999900000
#include <cstdio>
typedef long long int ll;

int main() {
	ll a, b;
	scanf_s_s("%lld %lld", &a, &b);
	if (a > b) {
		printf("%lld\n", a - b - 1);
		for (ll i = b + 1; i < a; i++) {
			printf("%llu ", i);
		}
	}
	else if(a < b){
		printf("%lld\n", b - a - 1);
		for (ll i = a + 1; i < b; i++) {
			printf("%lld ", i);
		}
	}
	else {
		printf("0\n");
	}
}