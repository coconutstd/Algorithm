#include <iostream>

using namespace std;
int a[8];
int check[8];
int n, m;

void go(int index) {
	if (index == m) {
		//Ãâ·Â
		for (int i = 0; i < m; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		a[index] = i;
		go(index + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	go(0);
	return 0;
}