#include <cstdio>
#include <algorithm>

using namespace std;

void D(int v) {
	if (v > 7) return;
	else {
		D(v * 2);
		D(v * 2 + 1);
		printf("%d ", v);
	}
}

int main() {
	D(1);
	return 0;
}