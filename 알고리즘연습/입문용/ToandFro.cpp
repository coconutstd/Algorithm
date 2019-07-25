#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

char w[200][200];

int main() {
	string s;
	int n;
	while (true) {
		memset(w, 0, sizeof(w));
		cin >> n;
		if (n == 0) { return 0; }
		cin >> s;
		int row = 0, col = 0;
		for (int i = 0; i < s.size(); i++) {
			if ((i / n) % 2 == 0) { col = i % n; }
			else { col = n - 1 - i % n; }
			row = i / n;
			w[row][col] = s[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= row; j++) {
				cout << w[j][i];
			}
		}
		cout << endl;
	}
}