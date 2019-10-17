/*
재미있는 오슬로 게임
배열 탐색 연습
모든 칸이 1과 2로 채워져 있지 않음을 주의
*/
#include <cstdio>
#include <cstring>

int map[9][9];
int n, m;
void oslo(int x, int y, int type) {

	for (int i = x + 1,j; i <= n; i++) {
		if (map[y][i] == 0) break;
		if (map[y][i] == type) {
			for (j = x; j < i; j++) {
				map[y][j] = (type == 1) ? 1 : 2;
			}break;
		}
	}

	for (int i = x - 1,j; i >= 1; i--) {
		if (map[y][i] == 0) break;
		if (map[y][i] == type) {
			for (j = x; j > i; j--) {
				map[y][j] = (type == 1) ? 1 : 2;
			}break;
		}
	}

	for (int i = y - 1, j; i >= 1; i--) {
		if (map[i][x] == 0) break;
		if (map[i][x] == type) {
			for (j = y; j > i; j--) {
				map[j][x] = (type == 1) ? 1 : 2;
			}break;
		}
	}

	for (int i = y + 1, j; i <= n; i++) {
		if (map[i][x] == 0) break;
		if (map[i][x] == type) {
			for (j = y; j < i; j++) {
				map[j][x] = (type == 1) ? 1 : 2;
			}break;
		}
	}

	for (int i = x + 1, j = y - 1,k1,k2; i <= n && j >= 1; i++, j--) {
		if (map[j][i] == 0) break;
		if (map[j][i] == type) {
			for (k1 = x, k2 = y; k1 < i; k1++, k2--) {
				map[k2][k1] = (type == 1) ? 1 : 2;
			}break;
		}
	}

	for (int i = x - 1, j = y + 1, k1, k2; i >= 1 && j <= n; i--, j++) {
		if (map[j][i] == 0) break;
		if (map[j][i] == type) {
			for (k1 = x, k2 = y; k1 > i; k1--, k2++) {
				map[k2][k1] = (type == 1) ? 1 : 2;
			}break;
		}
	}

	for (int i = x - 1, j = y - 1, k1, k2; i >= 1 && j >= 1; i--, j--) {
		if (map[j][i] == 0) break;
		if (map[j][i] == type) {
			for (k1 = x, k2 = y; k1 > i; k1--, k2--) {
				map[k2][k1] = (type == 1) ? 1 : 2;
			}break;
		}
	}

	for (int i = x + 1, j = y + 1,k1,k2; i <= n && j <= n; i++, j++) {
		if (map[j][i] == 0) break;
		if (map[j][i] == type) {
			for (k1 = x, k2 = y; k1 < i; k1++, k2++) {
				map[k2][k1] = (type == 1) ? 1 : 2;
			}break;
		}
	}

}

int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {
		
		scanf("%d %d", &n, &m);
		if (n == 0) { printf("#%d %d %d\n",test_case, 0,0); continue; }
		if (m == 0) { printf("#%d %d %d\n", test_case, 2, 2); continue; }
		int x = n / 2;
		map[x+1][x+1] = map[x][x] = 2;
		map[x + 1][x] = map[x][x + 1] = 1;

		for (int i = 0, a, b, c; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			oslo(a, b, c);
		}
		
		int black = 0, white = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				black += (map[i][j] == 1) ? 1 : 0;
				white += (map[i][j] == 2) ? 1 : 0;
			}
		}
		printf("#%d %d %d\n", test_case, black, white);

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] = 0;
			}
		}
	}
}