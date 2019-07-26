#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int ans = 10;
	for (int i = 0; i < s.size()-1; i++) {
		if (s[i] == s[i + 1]) {
			ans += 5;
		}
		else ans += 10;
	}
	cout << ans << endl;
}