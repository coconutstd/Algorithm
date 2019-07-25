#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		cout << "String #" << i+1 << endl;
		for (int j = 0; j < s.size(); j++) {
			char x = s[j];
			if (x == 'Z') {
				x = 'A';
			}
			else {
				x += 1;
			}
			cout << x;
		}
		cout << "\n\n";
	}
}