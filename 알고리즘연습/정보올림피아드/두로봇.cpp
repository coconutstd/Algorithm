/*
두 로봇
시작점에서 도착점으로 가는 단일 경로를 가중치의 합과 같이 구한후
경로에서 가장 큰 가중치를 가지는 값을 빼줌

*/

#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<pair<int,int>>> map;
vector<int> ch;
int n, s, e;
bool flag = false;
void dfs(int v, int sum) {
	if (flag) return;
	if (v == e) {
		flag = true;
		int max = -1;
		for (int i = 1; i <= n; i++) {
			if (max < ch[i]) max = ch[i];
		}
		int ans = sum - max;
		printf("%d\n", ans);
	}
	else {
		for (int i = 0; i < map[v].size();i++) {
			if (ch[map[v][i].first] == 0) {
				ch[map[v][i].first] = map[v][i].second;
				dfs(map[v][i].first, sum + map[v][i].second);
				ch[map[v][i].first] = 0;
			}
		}
	}
}

int main() {

	scanf("%d %d %d", &n, &s, &e);
	map.resize(n+1);
	ch.resize(n + 1,0);
	if (n == 1 || s == e) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		int from, to, l;
		scanf("%d %d %d", &from, &to, &l);
		map[from].push_back(make_pair(to, l));
		map[to].push_back(make_pair(from, l));
	}
	ch[s] = 1;
	dfs(s,0);

	return 0;
}
