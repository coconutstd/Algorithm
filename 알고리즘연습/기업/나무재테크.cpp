#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

int N, M, K;
const int MAX = 11;
const int dx[] = {-1,-1,0,+1,+1,+1,0,-1};
const int dy[] = { 0,+1,+1,+1,0,-1,-1,-1};
struct TREE {
	int row, col, age;
};
int a[MAX][MAX];
int eat[MAX][MAX];
bool operator<(TREE a, TREE b) {
	return (a.age > b.age);
}
priority_queue<TREE> pq[2];
queue<TREE> alive, dead;

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			scanf("%d", &a[r][c]);
			eat[r][c] = 5;
		}
	}
	TREE tree;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &tree.row, &tree.col, &tree.age);
		pq[0].push(tree);
	}

	int next, cur = 0;
	
	while (K--) {
		next = (cur + 1) % 2;
		//º½
		while (!pq[cur].empty()) {
			TREE cur_tree = pq[cur].top(); pq[cur].pop();
			int r = cur_tree.row; int c = cur_tree.col;
			if (eat[r][c] >= cur_tree.age) {
				eat[r][c] -= cur_tree.age;
				TREE next_tree;
				next_tree.row = cur_tree.row;
				next_tree.col = cur_tree.col;
				next_tree.age = cur_tree.age + 1;
				alive.push(next_tree);
				pq[next].push(next_tree);
			}
			else {
				dead.push(cur_tree);
			}
		}
		//¿©¸§
		while (!dead.empty()) {
			TREE cur_tree = dead.front(); dead.pop();
			int r = cur_tree.row; int c = cur_tree.col;
			eat[r][c] += (int)(cur_tree.age / 2);
		}

		while (!alive.empty()) {
			TREE cur_tree = alive.front(); alive.pop();
			if ((cur_tree.age % 5) == 0) {
				for (int i = 0; i < 8; i++) {
					TREE next_tree;
					next_tree.row = cur_tree.row + dx[i];
					next_tree.col = cur_tree.col + dy[i];
					next_tree.age = 1;
					if (1 <= next_tree.row && next_tree.row <= N && 1 <= next_tree.col && next_tree.col <= N) {
						pq[next].push(next_tree);
					}
				}
			}
		}
		//°Ü¿ï
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				eat[r][c] += a[r][c];
			}
		}
		cur = next;
	}
	printf("%d\n", pq[next].size());
}