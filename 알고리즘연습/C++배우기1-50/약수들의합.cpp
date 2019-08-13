#include <iostream>
#include <vector>
using namespace std;

class Number
{
private:
	bool perfect=false;
	vector<int> data;
	int num;
public:
	Number(int n) : num(n)
	{
		int sum = 0;
		for (int i = 1; i <= n/2; i++) {
			if (n % i == 0) {
				sum += i;
				data.push_back(i);
			}
		}
		if (sum == n) { perfect = true; }
	}
	bool isPerfect() { return perfect; }
	int getNum() { return num; }
	const vector<int>& getData() { return data; }
};

int main() {

	int n;
	while (true)
	{
		cin >> n;
		if (n == -1) {
			break;
		}
		else {
			Number input(n);
			if (input.isPerfect()) {
				vector<int> data;
				data = input.getData();
				cout << input.getNum() << " = ";
				for (int i = 0; i < data.size(); i++) {
					if (i == data.size() - 1) {
						cout << data[i] << "\n"; break;
					}
					cout << data[i] << " + ";
				}
			}
			else {
				cout << input.getNum() << " is NOT perfect.\n";
			}
		}
	}
	return 0;
}
