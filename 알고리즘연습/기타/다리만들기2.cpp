#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;
int n, m;
vector<vector<int>> visited;
vector<vector<int>> land;
map<pair<int, int>,int> bridge;

struct Node {
	int v, e, weight;
	bool operator<(Node const &e) {
		return weight < e.weight;
	}
};

const int MAX = 10001;
const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { -1,+1,0,0 };

int parent[MAX];

void numberingIsland(int cnt, int x, int y, vector<vector<int>>& land) {
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	land[x][y] = cnt;
	visited[x][y] = 1;
	while (!q.empty()) {
		int c_x = q.front().first;
		int c_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = c_x + dx[i];
			int ny = c_y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && visited[nx][ny] != 1 &&land[nx][ny] != 0) {
				q.push(make_pair(nx, ny));
				land[nx][ny] = cnt;
				visited[nx][ny] = 1;
			}
		}
	}
}

void makeRowBridge(int row) {
	int now = land[row][0];
	int end = 0;
	while(end < m) {
		// 0 이 아닌걸 찾는다
		for (int i = end; i < m; i++) {
			if (land[row][i] != 0) {
				now = land[row][i];
				end = i;
				break;
			}
			else {
				end++;
			}
		}
		// 끝을 찾는다
		for (int i = end; i < m; i++) {
			if (land[row][i] == 0) {
				end = i - 1;
				break;
			}
			else {
				end++;
			}
		}
		int start = end+1;
		// 시작을 찾는다
		for (int i = end+1; i < m; i++) {
			if (land[row][i] != 0) {
				start = i;
				//다리를 놓는다
				if (now != land[row][i]) {
					int leng = start - end - 1; // 다리 길이
					//cout << "row : " << row << " start : " << start << " end : " << end << endl;
					if (leng < 2) break;
					int one = min(land[row][i], now); // 섬 번호 1
					int two = max(land[row][i], now); // 섬 번호 2
					if (bridge.insert(make_pair(make_pair(one, two), leng)).second) {
						end = start;
					}
					else {
						int now = bridge[make_pair(one, two)];
						bridge[make_pair(one, two)] = min(now, leng);
						end = start;
					}
					break;
				}
				else {
					end = i;
				}
			}
		}
		end = start;
	}
}

void makeColBridge(int col) {
	int now = land[0][col];
	int end = 0;
	while (end < n) {
		// 0 이 아닌걸 찾는다
		for (int i = end; i < n; i++) {
			if (land[i][col] != 0) {
				now = land[i][col];
				end = i;
				break;
			}
			else {
				end++;
			}
		}
		// 끝을 찾는다
		for (int i = end; i < n; i++) {
			if (land[i][col] == 0) {
				end = i - 1;
				break;
			}
			else {
				end++;
			}
		}
		int start = end + 1;
		// 시작을 찾는다
		for (int i = end + 1; i < n; i++) {
			if (land[i][col] != 0) {
				start = i;
				if (now != land[i][col]) {
					//다리를 놓는다
					int leng = start - end - 1; // 다리 길이
					if (leng < 2) break;
					int one = min(land[i][col], now); // 섬 번호 1
					int two = max(land[i][col], now); // 섬 번호 2
					if (bridge.insert(make_pair(make_pair(one, two), leng)).second) {
						end = start;
					}
					else {
						int oldleng = bridge[make_pair(one, two)];
						bridge[make_pair(one, two)] = min(oldleng, leng);
						end = start;
					}
					break;
				}
				else {
					end = i;
				}
			}
		}
		end = start;
	}
}

int find(int node) {
	if (parent[node] == node) return node;
	else return parent[node] = find(parent[node]);
}

void merge(int node1, int node2) {
	node1 = find(node1);
	node2 = find(node2);
	if (node1 != node2) parent[node2] = node1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		vector<int> element(m, 0);
		land.push_back(element);
		visited.push_back(element);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> land[i][j];
		}
	}
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (land[i][j] != 0 && visited[i][j] == 0) {
				numberingIsland(cnt, i, j, land);
				cnt++;
			}
		}
	}


	//가로방향 다리 놓기
	for (int i = 0; i < n; i++) {
		makeRowBridge(i);
	}
	//세로방향 다리 놓기
	for (int i = 0; i < m; i++) {
		makeColBridge(i);
	}


	// 맵 정렬
	vector<Node> a(bridge.size());
	int index = 0;
	for (map<pair<int, int>, int>::iterator i = bridge.begin(); i != bridge.end(); i++) {
		a[index].v = i->first.first;
		a[index].e = i->first.second;
		a[index].weight = i->second;
		index++;
	}
	sort(a.begin(), a.end());

	//for (int i = 0; i < a.size(); i++) {
	//	cout << a[i].v << " " << a[i].e << " " << a[i].weight << endl;
	//}

	for (int i = 1; i < cnt; i++) {
		parent[i] = i;
	}
	int answer = 0;
	for (int i = 0; i < a.size(); i++) {
		if (find(a[i].v) != find(a[i].e)) {
			merge(a[i].v, a[i].e);
			answer += a[i].weight;
		}
	}

	for (int i = 1; i < cnt; i++) {
		parent[i] = find(parent[i]);
	}


	if (bridge.size() == 0) {
		cout << -1;
	}
	else {
		int p = parent[1];
		for (int i = 2; i < cnt; i++) {
			if (p != parent[i]) {
				cout << -1;
				return 0;
			}
		}
		cout << answer;
	}
}