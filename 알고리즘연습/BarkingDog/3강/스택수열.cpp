#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

class Sequence
{
	vector<char> s;
public:
	bool is_possible(vector<int>&);
	void print();
};

bool Sequence::is_possible(vector<int>& a) {
	stack<int> st;
	int num = 1;
	for (int i = 0; i < a.size(); i++) {
		while (true) {
			if (num <= a[i]) {
				st.push(num++);
				s.push_back('+');
			}
			else {
				if (a[i] == st.top()) {
					st.pop();
					s.push_back('-');
					break;
				}
				else return false;
			}
		}
	}
	return true;
}

void Sequence::print() {
	for (int i = 0; i < s.size(); i++) {
		printf("%c\n", s[i]);
	}
}

int main() {
	int n;
	scanf_s_s("%d", &n);
	vector<int> data;
	for (int i = 0; i < n; i++) {
		int t;
		scanf_s_s("%d", &t);
		data.push_back(t);
	}
	Sequence seq;
	if (seq.is_possible(data)) {
		seq.print();
	}
	else {
		printf("NO\n");
	}
}