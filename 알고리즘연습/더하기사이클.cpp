#include <iostream>
using namespace std;
int d[10001];
int self(int n) {
	int sum = 0;
	sum += n;
	do
	{
		sum += n % 10;
		n /= 10;
	} while (n != 0);
	return sum;
}

int main() {
	
	for (int i = 1; i <= 10000; i++) {
		int n = self(i);
		d[n]++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (d[i] == 0) printf("%d\n", i);
	}
}