#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Deque
{
	int n;
	int front_idx, rear_idx;
	vector<int> v;
public:  
	Deque(int _n) :n(_n), front_idx(0),rear_idx(0) { v.resize(n);  };
	int empty() { if (front_idx == rear_idx) return 1; else return 0; }
	int size() { return (rear_idx - front_idx + n) % n; }
	int front();
	int back();
	void push_front(int);
	void push_back(int);
	int pop_front();
	int pop_back();
	
};

int Deque::front() {
	if (empty()) {
		return -1;
	}
	else {
		return v[(front_idx + 1) % n];
	}
}

int Deque::back() {
	if (empty()) {
		return -1;
	}
	else {
		return v[rear_idx];
	}
}

void Deque::push_front(int val) {
	v[front_idx] = val;
	front_idx = (front_idx - 1 + n) % n;
}

void Deque::push_back(int val) {
	rear_idx = (rear_idx + 1) % n;
	v[rear_idx] = val;
}

int Deque::pop_front() {
	if (empty()) return -1;
	front_idx = (front_idx + 1) % n;
	return v[front_idx];
}

int Deque::pop_back() {
	int ret;
	if (empty())return -1;
	ret = v[rear_idx];
	rear_idx = (rear_idx - 1 + n) % n;
	return ret;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();
	Deque deq(n);
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