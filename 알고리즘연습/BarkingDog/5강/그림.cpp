#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Drawing
{
private:
	const int dx[4] = { -1,1,0,0 };
	const int dy[4] = { 0,0,-1,1 };
	int n, m;
	vector<vector<int>>& map;
	vector<vector<int>> visited;
	
public:
	Drawing(int _n, int _m, vector<vector<int>>& _map) : n(_n), m(_m), map(_map)
	{
		for (int i = 0; i < n; i++)
		{
			vector<int> element(m, 0);
			visited.push_back(element);
		}
	}
	int Bfs(int x, int y);
	pair<int,int> FindLargestDrawing();
};

int Drawing::Bfs(int x, int y)
//그림의 크기를 리턴
{
	int size = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = 1;
	size++;
	while (!q.empty())
	{
		int c_x = q.front().first;
		int c_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];
			if (n_x >= 0 && n_x < n && n_y >= 0 && n_y < m && !visited[n_x][n_y] && map[n_x][n_y])
			{
				size++;
				q.push(make_pair(n_x, n_y));
				visited[n_x][n_y] = 1;
			}
		}
	}
	return size;
}

pair<int,int> Drawing::FindLargestDrawing()
{
	int max = -1;
	int cnt = 0;
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (!visited[x][y] && map[x][y])
			{
				int result = Bfs(x, y);
				cnt++;
				if (max < result)
				{
					max = result;
				}
			}
		}
	}
	if (cnt == 0) max = 0;
	return make_pair(cnt,max);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> map;
	for (int i = 0; i < n; i++)
	{
		vector<int> element(m);
		map.push_back(element);
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int t;
			cin >> t;
			map[i][j] = t;
		}
	}
	Drawing drawing(n, m, map);
	pair<int, int> result = drawing.FindLargestDrawing();
	cout << result.first << "\n" << result.second;
}