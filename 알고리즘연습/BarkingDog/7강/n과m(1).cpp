#include <iostream>

using namespace std;
int n, m;
int a[9], check[9];

void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i]) continue;
		check[i] = 1;
		a[index] = i;
		go(index + 1, n, m);
		check[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	go(0, n, m);
	return 0;
}