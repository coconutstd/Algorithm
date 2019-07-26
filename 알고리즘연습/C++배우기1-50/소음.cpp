#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	string s1, op,s2;
	cin >> s1 >> op >> s2;
	if (op[0] == '*') {
		for (int i = 0; i < s2.size() - 1; i++) {
			s1 += '0';
		}
		cout << s1 << endl;
	}
	else {
		int i, j;
		if (s1.size() > s2.size()) {
			i = s1.size() - 1; j = s2.size()-1;
			for (i, j; j >= 0; j--, i--) {
				s1[i] = s2[j] + s1[i] - '0';
			}
			cout << s1 << endl;
		}
		else {
			i = s2.size() - 1; j = s1.size() - 1;
			for (i, j; j >= 0; j--, i--) {
				s2[i] = s1[j] + s2[i] - '0';
			}
			cout << s2 << endl;
		}
	}
}   