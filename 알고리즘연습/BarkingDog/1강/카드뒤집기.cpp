#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v(21);
	for (int i = 1; i <= 20; i++) {
		v[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		int a, b;
		scanf_s_s("%d %d", &a, &b);
		reverse(v.begin() + a, v.begin() + b+1);
	}
	for (int i = 1; i <= 20; i++) {
		printf("%d ", v[i]);
	}

}