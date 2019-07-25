#include <iostream>
#include <queue>
using namespace std;
const int bits[4] = { 0b1000,0b0100,0b0010,0b0001 };
const int dx[4] = {+1,0,-1,0 };
const int dy[4] = { 0,+1,0,-1 };
int map[50][50];
bool visit[50][50];
int room_no[50][50];
int rooms[2500];
int m, n;


int bfs(pair<int, int> start, int count) {
	int size = 1;
	queue<pair<int, int>> q;
	q.push(start);
	visit[start.first][start.second] = true;
	room_no[start.first][start.second] = count;
	while (!q.empty()) {
		int x = q.front().first; int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !visit[nx][ny]) {
				if (!(map[x][y] & bits[i])) {
					q.push(make_pair(nx, ny));
					room_no[nx][ny] = count;
					visit[nx][ny] = true;
					size++;
				}
			}
		}
	}
	return size;
}


int main() {
	
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			map[i][j] = a;
		}
	}

	
	int count = 0, room_size=0, max= 0, max_room_no;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j]) {
				room_size = bfs(make_pair(i, j),count);
				if (room_size > max) {
					max = room_size;
				}
				rooms[count] = room_size;
				count++;
			}
		}
	}

	int max2 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k]; int ny = j + dy[k];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && room_no[i][j] != room_no[nx][ny]) {
					int sum = rooms[room_no[i][j]] + rooms[room_no[nx][ny]];
					if (sum > max2) {
						max2 = sum;
					}
				}
			}
		}
	}

	cout << count << "\n" << max << "\n"<<  max2 <<endl;


}