#include <iostream>
using namespace std;
int arr[2];
int main() {
	int n;
	cin >> n;
	cin.ignore();
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		arr[s[i] - 'A']++;
	}
	if (arr[0] > arr[1]) {
		cout << "A\n";
	}
	else if (arr[0] == arr[1]) {
		cout << "Tie\n";
	}
	else {
		cout << "B\n";
	}
}