#include<iostream>
#include<memory.h>
using namespace std;

int K;
int d[5][8];
int change[5];
int change_rotate[5];
const int score[] = { 1,2,4,8 };

int main()
{
	int T;

	scanf("%d", &T);

	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	while(T--){
		scanf("%d", &K);
		for (int i = 1; i < 5; i++) {
			for (int j = 0; j < 8; j++) {
				scanf("%d", &d[i][j]);
			}
		}
		while (K--) {
			memset(change, -1, sizeof(change));
			int t, r;
			scanf("%d %d", &t, &r);
			change[t] = t;
			change_rotate[t] = r;
			for (int left = t - 1; left >= 0; left--) {
				int right = left + 1;
				if (d[left][2] != d[right][6]) {
					change[left] = left;
					change[right] = right;
					change_rotate[left] = change_rotate[right] * -1;
				}
				else {
					break;
				}
			}
			for (int right = t + 1; right <= 4; right++) {
				int left = right - 1;
				if (d[left][2] != d[right][6]) {
					change[left] = left;
					change[right] = right;
					change_rotate[right] = change_rotate[left] * -1;
				}
				else {
					break;
				}
			}

			for (int i = 1; i < 5; i++) {
				if (change[i] != -1) {
					if (change_rotate[i] == 1) {
						int temp;
						temp = d[change[i]][7];
						for (int j = 6; j >= 0; j--) {
							d[change[i]][j + 1] = d[change[i]][j];
						}
						d[change[i]][0] = temp;
					}
					else if (change_rotate[i] == -1) {
						int temp;
						temp = d[change[i]][0];
						for (int j = 1; j <= 7; j++) {
							d[change[i]][j - 1] = d[change[i]][j];
						}
						d[change[i]][7] = temp;
					}
				}
			}
		}


		int ans = 0;
		for (int i = 1; i < 5; i++) {
			if (d[i][0] == 1) {
				ans += score[i - 1];
			}
		}
		printf("#%d\n", ans);
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}