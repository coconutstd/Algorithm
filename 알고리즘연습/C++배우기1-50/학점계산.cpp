#include <iostream>
#include <iomanip>
using namespace std;
double grade[6] = {4.0,3.0,2.0,1.0,0.0,0.0};

int main() {
	char s1[4];
	scanf_s_s("%s", &s1);
	double res = grade[s1[0] - 'A'];
	if (s1[0] == 'F') { printf("%.1f\n", res); return 0; }
	if (s1[1] == '0') {
		printf("%.1f\n", res);
	}
	else {
		if (s1[1] == '+') {
			res += 0.3;
		}
		else {
			res -= 0.3;
		}
		printf("%.1f\n", res);
	}
}