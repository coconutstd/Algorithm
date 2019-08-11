#include <iostream>
#include <string>
#include <deque>
using namespace std;

class Deque
{
	deque<int> dq;
public:
	int size() { return dq.size(); }
	int empty() { if (dq.empty())return 1; else return 0; }
	int front() { if (dq.empty())return -1; else return dq.front(); }
	int back() { if (dq.empty())return -1; else return dq.back(); }
	void push_front(int val) { dq.push_front(val); }
	void push_back(int val) { dq.push_back(val); }
	int pop_front();
	int pop_back();
};

int Deque::pop_front() {
	if (dq.empty()) return -1;
	int t = dq.front(); dq.pop_front();
	return t;
}

int Deque::pop_back() {
	if (dq.empty()) return -1;
	int t = dq.back(); dq.pop_back();
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cin.ignore();
	Deque deq;
	for (int i = 0; i < n; i++) {
		string input;
		string val;
		cin >> input;
		if (input == "push_back") {
			cin >> val;
			deq.push_back(stoi(val));
		}
		else if (input == "push_front") {
			cin >> val;
			deq.push_front(stoi(val));
		}
		else if (input == "pop_back") {
			cout << deq.pop_back() << "\n";
		}
		else if (input == "pop_front") {
			cout << deq.pop_front() << "\n";
		}
		else if (input == "size") {
			cout << deq.size() << "\n";
		}
		else if (input == "empty") {
			cout << deq.empty() << "\n";
		}
		else if (input == "front") {
			cout << deq.front() << "\n";
		}
		else if (input == "back") {
			cout << deq.back() << "\n";
		}
	}
}