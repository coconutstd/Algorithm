#include <iostream>
#include <queue>
using namespace std;

typedef priority_queue<int, vector<int>, less<int>> maxpq;
typedef priority_queue<int, vector<int>, greater<int>> minpq;

class Flatten
{
public:
	void dump(maxpq&, minpq&);
	int answer(maxpq&, minpq&);
	bool is_flat(maxpq&, minpq&);
};

void Flatten::dump(maxpq& a, minpq& b) {
	int max = a.top(); a.pop(); int min = b.top(); b.pop();
	max--; min++;
	a.push(max); b.push(min);
}

int Flatten::answer(maxpq& a, minpq& b) {
	return a.top() - b.top();
}

bool Flatten::is_flat(maxpq& a, minpq& b) {
	if (a.top() - b.top() == 0 || a.top() - b.top() == 1) {
		return true;
	}
	else false;
}

int main() {
	int test_case,T =1;
	for (int test_case = 1; test_case <= T; test_case++) {
		int d,h;
		cin >> d;
		maxpq max; minpq min;
		for (int i = 0; i < 100; i++) {
			cin >> h;
			max.push(h); min.push(h);
		}
		Flatten flatten;
		while (d--) {
			if (!flatten.is_flat(max, min)) {
				flatten.dump(max, min);
			}
			else {
				break;
			}	
		}
		cout << "#" <<test_case << " "<<flatten.answer(max,min) << endl;
	}

}