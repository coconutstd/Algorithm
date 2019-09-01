#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> Map;

int N;
const int dx[4] = { 0,0,-1,+1 };
const int dy[4] = { -1,+1,0,0 };

void FallRain(Map& copy, int height) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			// 비오면 접근 할 수 없는 영역으로 설정 -1
			if (copy[i][j] <= height) copy[i][j] = -1;
		}
	}
}

void bfs(Map& map, int i, int j) {
	queue<pair<int,int>> q;
	q.push(make_pair(i, j));
	map[i][j] = -1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny< N && map[nx][ny] != -1) {
				q.push(make_pair(nx, ny));
				map[nx][ny] = -1;
			}
		}
	}
}

void dfs(Map& map, int i, int j) {
	//기저조건
	if (i < 0 || i >= N || j < 0 || j >= N || map[i][j] == -1) return;
	map[i][j] = -1;
	dfs(map, i + 1, j);
	dfs(map, i - 1, j);
	dfs(map, i, j+1);
	dfs(map, i, j-1);
}

int main()
{
	set<int> s;
	Map map;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;



	for (int i = 0; i < N; ++i) {
		vector<int> element(N, 0);
		map.push_back(element);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int t;
			cin >> t;
			map[i][j] = t;
			s.insert(t);
		}
	}
	if (s.size() == 1) {
		cout << "1";
		return 0;
	}
	int max = -1;
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
		//장마를 낮은 순서부터 내림
		Map copy = map;
		FallRain(copy, *it);
		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (copy[i][j] != -1) {
					cnt++;
					bfs(copy, i, j);
				}
			}
		}
		if (max < cnt) {
			max = cnt;
		}
	}
	cout << max;
}
