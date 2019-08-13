#include <iostream>
using namespace std;

struct Max
{
	Max(string n, int a) : name(n), amt(a){

	}
	string name;
	int amt;
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cin.ignore();
		Max max("h",0);
		string name;
		int amt;
		for (int i = 0; i < n; i++) {
			cin >> name >> amt;
			if (max.amt < amt) {
				max.name = name;
				max.amt = amt;
			}
		}
		cout << max.name << "\n";
	}
}