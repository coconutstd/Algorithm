#include <iostream>
#include <string>
using namespace std;

class Memory
{
public:
	int restore(string s);
};

int Memory::restore(string s) {
	int cnt = 0;
	if (s[0] == '1') { cnt++; }
	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] == s[i]) continue;
		else cnt++;
	}
	return cnt;
}

int main() {
	int t,cnt=1;
	cin >> t;
	Memory my_mem;
	while (t--) {
		string s;
		cin >> s;
		cout << "#" << cnt << " " << my_mem.restore(s) << endl;
		cnt++;
	}
}