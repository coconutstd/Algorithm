#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	while (cin >> s) {
		if (s[0] == '0') { break; }
		while (s.size() != 1) {
			int size = s.size();
			int sum = 0;
			for (int i = 0; i < size; i++) {
				sum += s[i] - '0';
				
			}
			s = to_string(sum);
		}
		cout << s << endl;
	}
}