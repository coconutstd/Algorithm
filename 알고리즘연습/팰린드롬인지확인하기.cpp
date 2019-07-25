#include <iostream>
#include <string>

using namespace std;

int main() {
	string a;
	cin >> a;
	int size = a.size();
	for (int i = 0; i <= size / 2; i++) {
		if (a[i] != a[size - i - 1]) {
			cout << "0" << endl;
			return 0;
		}
	}
	cout << "1" << endl;
	return 0;
}