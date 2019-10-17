/*
7
27 33 80 73 19 23 15
48 84 61 3 36 9 62
87 57 3 14 69 17 22
17 57 86 21 85 51 82
7 94 66 21 19 41 82
27 5 59 28 26 77 64
5 46 4 63 76 99 8
*/

#include <stdio.h>
#include <vector>
using namespace std;

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };

int main() {
	int n;
	scanf_s("%d", &n);
	vector<vector<int>> map;
	for (int i = 0; i <= n+1; i++) {
		vector<int> element(n + 2,0);
		map.push_back(element);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf_s("%d", &map[i][j]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			bool flag = true;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (map[i][j] <= map[nx][ny]) flag = false;
			}
			if (flag) ans++;
		}
	}
	printf("%d\n", ans);
}