#include <cstdio>
#include <queue>
#include <deque>
using namespace std;

int n, m;
int visited1[21][21];
int visited2[21][21];
struct coin
{
	coin(int _x = 0, int _y = 0) :x(_x), y(_y) {};
	int x, y;
};
char arr[21][21];
coin coins[2];

const int dx[] = { 0,0,1,-1 };
const int dy[] = { -1,1,0,0 };

int main() {
	int cnt = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			scanf("%c", &c);
			if (c == '\n') { j--; continue; }
			arr[i][j] = c;
			if (c == 'o') {
				coins[cnt].x = j; coins[cnt].y = i;
				cnt++;
			}
		}
	}

	queue<coin> q1, q2;
	deque<coin> nq;
	q1.push(coins[0]); visited1[coins[0].y][coins[0].x];
	q2.push(coins[1]); visited2[coins[1].y][coins[1].x];
	int drop = 0;
	int step = 1;

	while (!q1.empty()) {
		int ix1 = q1.front().x; int iy1 = q1.front().y;
		int ix2 = q2.front().x; int iy2 = q2.front().y;

		while (!q1.empty()) {
			int x1 = q1.front().x; int y1 = q1.front().y; q1.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x1 + dx[i]; int ny = y1 + dy[i];
				if (arr[ny][nx] != '#') {
					coin new_c(nx, ny);
					nq.push_front(new_c);
				}
				else {
					coin new_c(nx - dx[i], ny - dy[i]);
					nq.push_front(new_c);
				}
			}
		}

		while (!q2.empty()) {
			int x1 = q2.front().x; int y1 = q2.front().y; q2.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x1 + dx[i]; int ny = y1 + dy[i];
				if (arr[ny][nx] != '#') {
					coin new_c(nx, ny);
					nq.push_back(new_c);
				}
				else {
					coin new_c(nx - dx[i], ny - dy[i]);
					nq.push_back(new_c);
				}
			}
		}

		while (!nq.empty()) {
			drop = 0;
			int x1 = nq.front().x; int y1 = nq.front().y; nq.pop_front();
			int x2 = nq.back().x; int y2 = nq.back().y; nq.pop_back();
			
			if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) { drop++; }
			if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n) { drop++; }
			if (drop == 1) {
				printf("%d\n", step);

				return 0;
			}
			if (x1 == x2 && y1 == y2) { continue; }
			if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) { continue; }
			if (ix1 == x1 && iy1 == y1 && ix2 == x2 && iy2 == y2) { continue; }
			//printf("%d %d , %d %d\n", y1, x1, y2, x2);
			if ((ix1 == x1 && iy1 == y1) || (ix2 == x2 && iy2 == y2)) {
				q1.push(coin(x1, y1)); visited1[y1][x1] = 1;
				q2.push(coin(x2, y2)); visited2[y2][x2] = 1;
			}
			if (!visited1[y1][x1] && !visited2[y2][x2]) {
				q1.push(coin(x1, y1)); visited1[y1][x1] = 1;
				q2.push(coin(x2, y2)); visited2[y2][x2] = 1;
			}
		
		}
		step++;
		if (step > 11) {
			printf("-1\n");

			return 0;

		}
	}
	printf("-1\n");


}