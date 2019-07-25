#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

int T;
char out[51];
char input[51];

int main() {
	scanf("%d", &T);
	int cnt = 0;
	while (T--) {
		memset(input, '\0', sizeof(input));
		scanf("%s", input);
		int mul = 1;
		int index = 0;
		for (char x : input) {
			if (65 <= x && x <= 90 && cnt == 0) {
				printf("%c", x);
				continue;
			}
			if (x == '(') {
				cnt++;
				continue;
			}
			if (48 <= x && x <= 57) {
				mul *= x - '0';
				continue;
			}
			if (x == ')') {
				cnt--;
				if (cnt == 0) {
					for (int i = 0; i < mul; i++) {
						printf("%s", out);
					}
					index = 0;
				}
				continue;
			}
			else {
				out[index++] = x;
				continue;
			}
		}
		memset(out, '\0', sizeof(out));
		printf("\n");
	}
}