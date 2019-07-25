#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string a = "";
		cin >> a;
		v.push_back(a);
	}
	int size = v[0].size();
	string answer = "";
	bool is_same;
	for (int i = 0; i < size; i++) {
		is_same = true;
		for (int j = 0; j < n - 1; j++) {
			if (v[j][i] != v[j + 1][i]) {
				answer += "?";
				is_same = false;
				break;
			}
		}
		if (is_same == true) answer += v[0][i];
	}

	cout << answer << endl;
	
}