#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, e, start;
int f, t;
vector<int> a[1001];
bool check[1001];
queue<int> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front(); q.pop();
		cout << x << " ";
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (check[y] == false) {
				check[y] = true;
				q.push(y);
			}
		}
	}
}

void dfs(int x) {
	check[x] = true;
	cout << x << " ";
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (check[y] == false) {
			dfs(y);
		}
	}
}

int main() {

	cin >> n >> e >> start;
	
	for (int i = 0; i < e; i++) {
		cin >> f >> t;
		a[f].push_back(t);
		a[t].push_back(f);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	dfs(start);
	for (int i = 0; i < 1001; i++) {
		check[i] = false;
	}
	cout << "\n";
	check[start] = true;
	q.push(start);
	bfs();

	return 0;
}