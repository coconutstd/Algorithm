#include <iostream>
using namespace std;
int a[8];
int main() {
	bool b = true;
	for (int i = 0; i < 8; i++) {
		scanf("%d", &a[i]);
	}

	if (a[0] == 1) {
		for (int i = 1; i <= 7; i++) {
			if (a[i - 1] > a[i]) {
				b = false;
				break;
			}
		}
		if(b)printf("ascending");
	}
	else if (a[0] == 8) {
		for (int i = 1; i <= 7; i++) {
			if (a[i - 1] < a[i]) {
				b = false;
				break;
			}
		}
		if(b)printf("descending");
	}
	else {
		b = false;
	}
	if (!b) {
		printf("mixed");
	}
}