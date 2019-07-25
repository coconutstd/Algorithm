#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<vector<int>> adj;
vector<bool> visited;
vector<bool> discovered;

void dfs(int here) {
	printf("%d ", here);
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!visited[there]) {
			dfs(there);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	vector<int> order;
	q.push(start);
	discovered[start] = true;
	while (!q.empty()) {
		int here = q.front(); q.pop();
		order.push_back(here);
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i];
			if (!discovered[there]) {
				q.push(there);
				discovered[there] = true;
			}
		}
	}
	for (auto& vertex : order) {
		printf("%d ", vertex);
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &V);
	adj.resize(N + 1);
	visited = vector<bool>(adj.size(), false);
	discovered = vector<bool>(adj.size(), false);
	for (int i = 0; i < M; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	for (int i = 0; i < adj.size(); i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(V);
	printf("\n");
	bfs(V);

}