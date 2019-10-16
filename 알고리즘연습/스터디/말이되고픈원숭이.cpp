#include <cstdio>
#include <queue>
using namespace std;

int r, c;
int map[201][201];
bool check[201][201];
int k;

const int dr[] = { 0,0,-1,1 };
const int dc[] = { -1,1,0,0 };



int main() {
	scanf_s_s("%d", &k);
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			scanf_s_s("%d", &map[i][j]);
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	check[1][1] = true;

	while (!q.empty()) {
		int row = q.front().first; int col = q.front().second; q.pop();

	}
	

}