#include <iostream>


using namespace std;

int main() {
	int a, b;
	ios_base::sync_with_stdio(0); cin.tie(0);;
	while (cin >> a >> b) {
		if (a == 0 && b == 0) break;
		cout << a + b << endl;
	}
}