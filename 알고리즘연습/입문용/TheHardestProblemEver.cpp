#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	while (true) {
		getline(cin, str);
		if (str == "ENDOFINPUT") { return 0; }
		if (str == "END") { continue; }
		if (str == "START") {
			getline(cin, str);
			for (int i = 0; i < str.size(); i++) {
				char x;
				if (isalpha(str[i])) {
					if (str[i] - 'A' - 5 < 0) {
						x = 'Z' + str[i] - 'A' - 5 + 1;
						cout << x;
					}
					else {
						x = str[i] - 5;
						cout << x;
					}
				}
				else {
					cout << str[i];
				}
			}
			cout << endl;
		}
	}
}