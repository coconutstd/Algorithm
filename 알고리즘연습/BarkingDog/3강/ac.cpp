#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		deque<int> dq;
		int n;
		string f,arr;
		cin >> f >> n >> arr;
		string num = "";
		for (char& x : arr) {
			if (isalnum(x)) {
				num += x;
			}
			else {
				if (num.size() != 0) {
					dq.push_back(stoi(num));
					num = "";
				}
			}
		}
		//sw 1이면 정상출력, 0이면 뒤집어 출력
		bool sw = 1,error=0;
		for (int i = 0; i < f.size(); i++) {
			if (f[i] == 'R') {
				if (sw)sw = 0; else sw = 1;
			}
			if (f[i] == 'D') {
				if (!dq.empty()) {
					if (sw) {
						dq.pop_front();
					}
					else dq.pop_back();
				}
				else {
					error = 1;
				}
			}
		}

		if (!error) {
			cout << "[";
			if (sw) {
				for (int i = 0; i < dq.size(); i++) {
					if (i == dq.size() - 1) {
						cout << dq[i]; continue;
					}
					cout << dq[i] << ",";
				}
			}
			else {
				for (int i = dq.size()-1; i >=0; i--) {
					if (i == 0) {
						cout << dq[i]; continue;
					}
					cout << dq[i] << ",";
				}
			}
			cout << "]\n";
		}
		else {
			cout << "error\n";
		}
	}
}