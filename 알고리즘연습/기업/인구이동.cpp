#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2501;
const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
int N, L, R;
int cnt,ans;
bool check[51][51];
int map[51][51];
int a = 0;
struct info {
	info(int _x=0, int _y=0, int _val=0) :x(_x), y(_y), val(_val) {}
	int x, y, val;
};

vector<vector<info>> uni;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			check[i][j] = false;
		}
	}
	uni.clear();
	uni.resize(MAX);
}

void dfs(pair<int,int> start) {

	int x = start.first; int y = start.second;
	check[x][y] = true;
	uni[cnt].push_back(info(x,y,map[x][y]));
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; int ny = y + dy[i];
		if (0 > nx || nx >= N || 0 > ny || ny >= N)continue;
		int val = abs(map[x][y] - map[nx][ny]);
		if (!check[nx][ny] && L <= val && val <= R) {
			check[nx][ny] = true;
			dfs(make_pair(nx, ny));	
		}
	}
}

bool move(vector<vector<info>>& v,int cnt) {
	bool end = true;
	for (int i = 0; i < cnt; i++) {
		if (v[i].size() >= 2) {
			end = false;
			float sum = 0;
			int p;
			for (int j = 0; j < v[i].size(); j++) {
				sum += v[i][j].val;
			}
			p = sum / v[i].size();

			for (int j = 0; j < v[i].size(); j++) {
				map[v[i][j].x][v[i][j].y] = p;
			}
		}
	}
	if (end == true) return true;
	else {
		init();
		return false;
	}
}

int main() {
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	uni.resize(MAX);

	while (1) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!check[i][j]) {
					dfs(make_pair(i, j));
					cnt++;
				}
			}
		}
		if (move(uni, cnt) == true) {
			printf("%d\n", ans);
			break;
		}
		else {
			cnt = 0;
			ans++;
		}
	}
}