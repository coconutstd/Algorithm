#include <iostream>
#include <memory.h>
#include <string>

using namespace std;

int a[26];
int b[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		string s;
		getline(cin, s);
		int j;
		for (int i = 0; i < s.size(); i++) {
			
			a[s[i] - 'a']++;
			if (s[i] == ' ') { j = i + 1; break; }
		}
		for (j; j < s.size(); j++) {
			b[s[j] - 'a']++;
		}
		
		bool is_possible = true;
		for (int i = 0; i < 26; i++) {
			if (a[i] != b[i]) { is_possible = false; break; }
		}
		if (is_possible) {
			printf("Possible\n");
		}
		else printf("Impossible\n");
	}
}

