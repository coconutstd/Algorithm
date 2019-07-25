#include <iostream>
#include <string>
using namespace std;

class Math
{
public:
	double calc(string);
};
double Math::calc(string s) {
	double sum; int index = 0;
	string tmp;
	while (s[index] != ' ') {
		tmp += s[index];
		index++;
	}
	sum = stod(tmp);
	for (int i = index; i < s.size(); i++) {
		if (s[i] != ' ') {
			if (s[i] == '@') { sum *= 3.0; }
			else if (s[i] == '%') { sum += 5.0; }
			else if (s[i] == '#') { sum -= 7.0; }
		}
	}
	return sum;
}

int main() {
	int t;
	scanf("%d", &t);
	cin.ignore();
	Math math;
	while (t--) {
		string s;
		getline(cin, s);
		printf("%.2f\n", math.calc(s));
	}
}