#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100002;
bool check[MAX + 1];
int dist[MAX + 1];
int N, K;

int main() {
	scanf("%d %d", &N, &K);
	queue<int> q;
	q.push(N);
	check[N] = true;
	dist[N] = 0;
	while (!q.empty()) {
		int here = q.front(); q.pop();
		if (here - 1 >= 0) {
			if (!check[here - 1]) {
				q.push(here - 1);
				check[here - 1] = true;
				dist[here - 1] = dist[here] + 1;
			}
		}
		if (here + 1 < MAX) {
			if (!check[here + 1]) {
				q.push(here + 1);
				check[here + 1] = true;
				dist[here + 1] = dist[here] + 1;
			}
		}
		if (here * 2 < MAX) {
			if (!check[here * 2]) {
				q.push(here * 2);
				check[here * 2] = true;
				dist[here * 2] = dist[here] + 1;
			}
		}
	}
	printf("%d", dist[K]);
}

