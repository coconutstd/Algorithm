#include <iostream>
#include <string>

using namespace std;
char che[1000];
char alpha[1000];
char number[1000];
string a;
int c_cnt;
int n_cnt;
int main(void) {
	int a = 0;
	int i = 999, j = 0;
	scanf("%s", che);
	while (che[a] != NULL) {
		char c = che[a];
		//printf("%d\n", c);
		if (65 <= c && c <= 90) {
			c_cnt++;
			alpha[i--] = c;
		}
		else if (97 <= c && c <= 122) {
			alpha[i--] = c;
		}
		else if (48 <= c && c <= 57) {
			n_cnt++;
			number[j++] = c;
		}

		a++;
	}
	if (c_cnt != n_cnt) {
		printf("error");
	}
	else {
		int l = 999, m = 0;
		while (c_cnt--) {
			if (97 <= alpha[l - 1] && alpha[l - 1] <= 122) {
				if (number[m] == '1') {
					printf("%c%c", alpha[l], alpha[l - 1]);
					l = l - 2;
					m = m + 1;
				}
				else {
					printf("%c%c%c", alpha[l], alpha[l - 1], number[m]);
					l = l - 2;
					m = m + 1;
				}

			}
			else {
				if (number[m] == '1') {
					printf("%c", alpha[l]);
					l = l - 1;
					m = m + 1;
				}
				else {
					printf("%c%c", alpha[l], number[m]);
					l = l - 1;
					m = m + 1;
				}
			}

		}
	}

}