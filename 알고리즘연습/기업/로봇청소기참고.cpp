#include <stdio.h>
int main() {
	register int i, j;
	int move_r, move_c, r, c, d, result = 0, N, M;
	int map[52][52];
	int back_rr[] = { 1, 0, -1, 0 };
	int for_rr[] = { 0, -1, 0, 1 };
	int for_cc[] = { -1, 0, 1, 0 };
	scanf("%d %d %d %d %d", &N, &M, &r, &c, &d);
	for (i = 0; i <= N + 1; i++) {
		map[i][0] = map[i][M + 1] = 1;
	}
	for (i = 0; i <= M + 1; i++) {
		map[0][i] = map[N + 1][i] = 1;
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	r++; c++;
	while (1) {
		if (map[r][c] == 0) {
			map[r][c] = 2;
			result++;
		}
		if (map[r - 1][c] != 0 && map[r + 1][c] != 0 && map[r][c - 1] != 0 && map[r][c + 1] != 0) {
			r = r + back_rr[d]; c = c + for_rr[d];
			if (map[r][c] == 1) break;
		}
		else {
			move_r = r + for_rr[d]; move_c = c + for_cc[d];
			d = (d + 3) % 4;
			if (map[move_r][move_c] == 0) {
				r = move_r; c = move_c;
			}
		}
	}
	printf("%d\n", result);
	return 0;
}