/*
 백준 7562 번 : 나이트의 이동

 해결 : 2차원 배열에서 8방향으로의 Bfs를 구현함
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Knight
{

private:
	const int dx[8] = { -2,-1,-2,-1,+2,+1,+2,+1 };
	const int dy[8] = { -1,-2,+1,+2,-1,-2,+1,+2 };
	queue<pair<int, int>>& Q;
	vector<vector<int>>& Map;
	int I;

public:
	Knight(vector<vector<int>>& _Map, queue<pair<int,int>>& _Q, int _I):Map(_Map),Q(_Q),I(_I){}
	int Bfs(pair<int,int> Destination);
};

int Knight::Bfs(pair<int, int> Destination)
{
	int ret = 1;
	while (!Q.empty())
	{
		int size = Q.size();
		for (int i = 0; i < size; ++i)
		{
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();
			for (int j = 0; j < 8; ++j)
			{
				int nx = dx[j] + x;
				int ny = dy[j] + y;
				if (0 <= nx && nx < I && 0 <= ny && ny < I && Map[nx][ny] == 0)
				{
					if (nx == Destination.first && ny == Destination.second) return ret;
					Q.push(make_pair(nx, ny));
					Map[nx][ny] = 1;
				}
			}
		}
		ret++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, I;
	int x1, y1, x2, y2;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> I >> x1 >> y1 >> x2 >>y2;

		vector<vector<int>> Map;
		for (int j = 0; j < I; ++j)
		{
			vector<int> element(I, 0);
			Map.push_back(element);
		}

		queue<pair<int, int>> Q;
		Q.push(make_pair(x1, y1));
		Map[x1][y1] = 1;

		if (x1 == x2 && y1 == y2)
		{
			cout << "0\n";
		}
		else
		{
			Knight knight(Map, Q, I);
			cout << knight.Bfs(make_pair(x2, y2)) << "\n";
		}
	}
}


