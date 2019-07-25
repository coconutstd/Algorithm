#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string> v;
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			v.push_back(s);
		}
		bool answer = true;
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size() - 1; i++)
		{
			if (v[i] == v[i + 1].substr(0, v[i].size()))
			{
				answer = false;
				break;
			}
		}
		if (answer) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}
}