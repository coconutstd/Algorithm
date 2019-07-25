#include <iostream>
using namespace std;

int main() {
	int x,cnt=1,i=1;
	scanf("%d", &x);
	while (1) {
		i += cnt++;
		if (i > x) {
			if (cnt % 2 == 0) {
				i -= --cnt;
				printf("%d/%d\n", cnt - (x - i), 1 + (x - i));
				break;
			}
			else {
				i -= --cnt;
				printf("%d/%d\n", 1 + (x - i), cnt - (x - i));
				break;
			}
		}
	}
}