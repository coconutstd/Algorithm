#include <iostream>
#include <memory.h>
using namespace std;
int T,n;
int s[1000];
int main() {
	scanf("%d", &T);
	while (T--) {
		memset(s, 0, sizeof(s));
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &s[i]);
			sum += s[i];
		}
		double avg = double(sum) / n;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (double(s[i]) > avg) cnt++;
		}
		printf("%.3f%%\n", (double)cnt / n * 100);
	}
	 
}