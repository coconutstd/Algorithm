/*
���������
1���� �迭 �ε����� 2���� �迭 ���� �̿��ϴ� ����
*/
#include <stdio.h>
#include <cstring>
using namespace std;

int a[9][9];
int b[10];
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		
		bool flag = true;
		memset(b, 0, sizeof(b));
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				b[a[i][j]]++;
			}
			for (int k = 1; k <= 9; k++) {
				if (b[k] != 1) {
					flag = false;
					break;
				}
			}
			memset(b, 0, sizeof(b));
			if (!flag) break;
		}
		
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				b[a[j][i]]++;
			}
			for (int k = 1; k <= 9; k++) {
				if (b[k] != 1) {
					flag = false;
					break;
				}
			}
			memset(b, 0, sizeof(b));
			if (!flag) break;
		}
		
	
		for (int i = 0; i < 9; i+=3) {
			for (int j = 0; j < 9; j += 3) {
				for (int k = i; k < i + 3; k++) {
					for (int l = j; l < j + 3; l++) {
						b[a[k][l]]++;
					}
				}
				for (int p = 1; p <= 9; p++) {
					if (b[p] != 1) {
						flag = false;
						break;
					}
				}
				memset(b, 0, sizeof(b));
				if (!flag) break;
			}
			
		}
		
		if (flag) { printf("#%d %d\n", test_case, 1);}
		else { printf("#%d %d\n", test_case, 0); }
		
	}
}