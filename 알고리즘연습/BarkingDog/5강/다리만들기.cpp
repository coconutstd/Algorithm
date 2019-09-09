/*
 ���� 2146 �� : �ٸ� �����

 �ذ� : BFS�� ���� ������ ã�� ��ȣ�� �ο��Ѵ�. �� ������ BFS�� �����Ͽ� ���� ª�� �ٸ��� ã�´�.
*/

#include <iostream>
#include <vector>
#include <queue>
const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };
using namespace std;

vector<vector<int>> Map;
int N;
void bfs(int i, int j,int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	Map[i][j] = cnt;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 > nx || nx >= N || 0 > ny || ny >= N || Map[nx][ny] != 1) continue;
			q.push(make_pair(nx, ny));
			Map[nx][ny] = cnt;
		}
	}
}

int MakeBridge(int i, int j, vector<vector<int>> Map) {
	int size = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	int cnt = 0;
	while (!q.empty()) {
		size = q.size();
		for (int k = 0; k < size; k++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int p = 0; p < 4; ++p) {
				int nx = x + dx[p];
				int ny = y + dy[p];
				if (0 > nx || nx >= N || 0 > ny || ny >= N) continue;
				if (Map[nx][ny] != 0 && Map[nx][ny] != 1 && Map[nx][ny] != Map[i][j]) return cnt;
				if (Map[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					Map[nx][ny] = 1;
				}
			}
		}
		cnt++;
	}
	return 99999;
}

int main() {

	cin >> N;
	
	for (int i = 0; i < N; ++i) {
		vector<int> element(N, 0);
		Map.push_back(element);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> Map[i][j];
		}
	}
	//���� ��ȣ�� �Է��� 0,1���� �������� ���� 2������ ��ȣ �ο�
	int cnt = 2;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (Map[i][j] == 1) {
				bfs(i, j, cnt);
				cnt++;
			}
		}
	}

	int min = 9999;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (Map[i][j] != 0) {
				int res = MakeBridge(i, j, Map);
				if (res < min) {
					
					min = res;
				}
			}
		}
	}
	cout << min;


}
