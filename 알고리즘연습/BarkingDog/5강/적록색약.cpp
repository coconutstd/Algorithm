/*
 백준 10026 번 : 적록색약

 해결 : RGB 맵을 BFS한 후 맵을 다시 적록색약용을 변환 한 뒤 BFS 수행
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class RGB
{
private:
	const int dx[4] = { 0,0,-1,+1 };
	const int dy[4] = { -1,+1,0,0 };
	vector<vector<int>>& Map;
	vector<vector<int>>& Visited;
	int N;
public:
	RGB(vector<vector<int>>& _Map, vector<vector<int>>& _Visited, int _N):Map(_Map), Visited(_Visited), N(_N) {}
	void SetRG();
	void ResetVisited();
	int Bfs();
};


void RGB::SetRG()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (Map[i][j] == 1)
			{
				Map[i][j] = 0;
			}
		}
	}
}
void RGB::ResetVisited()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			Visited[i][j] = 0;
		}
	}
}

int RGB::Bfs()
{
	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (Visited[i][j] == 0)
			{
				queue<pair<int, int>> Q;
				Q.push(make_pair(i, j));
				Visited[i][j] = 1;
				while (!Q.empty())
				{
					int x = Q.front().first;
					int y = Q.front().second;
					Q.pop();
					for (int k = 0; k < 4; ++k)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (0 <= nx && nx < N && 0 <= ny && ny < N && Visited[nx][ny] != 1)
						{
							
							if (Map[x][y] == Map[nx][ny])
							{
								Q.push(make_pair(nx, ny));
								Visited[nx][ny] = 1;
							}
						}
					}
				}
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	int N;
	cin >> N;
	cin.ignore();
	vector<vector<int>> Map;
	vector<vector<int>> Visited;
	for (int i = 0; i < N; ++i)
	{
		vector<int> element(N, 0);
		Map.push_back(element);
		Visited.push_back(element);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			char t;
			cin >> t; 
			if (t == 'R')
			{
				Map[i][j] = 0;
			}
			else if (t == 'G')
			{
				Map[i][j] = 1;
			}
			else if (t == 'B')
			{
				Map[i][j] = 2;
			}
		}
	}

	RGB rgb(Map, Visited, N);

	cout << rgb.Bfs();
	rgb.ResetVisited();
	rgb.SetRG();
	cout << " " << rgb.Bfs();
}