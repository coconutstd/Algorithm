#include <iostream>
#include <math.h>
using namespace std;
int dp[1000000];

class Math
{
public:
	int sqrt_log_sin(int i);
};


int Math::sqrt_log_sin(int i)
{	
	if (dp[i] != 0) return dp[i];
	if (i <= 0) return dp[0];
	dp[i] = (this->sqrt_log_sin(floor(i - sqrt(i))) + this->sqrt_log_sin(floor(log(i))) + this->sqrt_log_sin(floor(i*sin(i)*sin(i)))) % 1000000;
	return dp[i];
}

int main(void) {

	Math my_math;
	dp[0] = 1;
	int input;
	while (true) {
		cin >> input;
		if (input == -1) { return 0; }
		cout << my_math.sqrt_log_sin(input) << endl;
	}
}