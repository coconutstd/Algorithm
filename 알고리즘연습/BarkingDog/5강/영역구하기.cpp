/*
 �������ϱ�

 2���� �迭�� ���簢���� �ش��ϴ� ������ -1�� ǥ��
 �� ��, -1�� �ƴ� ���� ��� ������ BFSŽ��
 
 * ��������� ������ ������ ũ���̹Ƿ� ��ǥ�� ������� ��ġ�� ����� 

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Area
{
private:
	const int dx[4] = { 0,0,-1,+1 };
	const int dy[4] = { -1,+1,0,0 };
	vector<vector<int>>& Map;
	int m, n;
public:
	Area(vector<vector<int>>& _Map, int _m, int _n):Map(_Map), m(_m), n(_n){}
	void FindArea();

private:
	int Bfs(int x, int y);
};

int Area::Bfs(int x, int y)
{
	int ret = 0;
	queue<pair<int, int>> Q;
	Q.push(make_pair(x, y));
	Map[x][y] = 1;
	ret++;
	while (!Q.empty())
	{
		int c_x = Q.front().first;
		int c_y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];
			if (0 <= n_x && n_x < m && 0 <= n_y && n_y < n && Map[n_x][n_y] == 0)
			{
				Q.push(make_pair(n_x, n_y));
				Map[n_x][n_y] = 1;
				ret++;
			}
		}
	}
	return ret;
}

void Area::FindArea()
{
	vector<int> answer;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; j++)
		{
			if (Map[i][j] == 0)
			{
				int t = Bfs(i, j);
				answer.push_back(t);
			}
		}
	}
	cout << answer.size() << '\n';
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << ' ';
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n, k;
	cin >> m >> n >> k;
	
	vector<vector<int>> Map;

	for (int i = 0; i < m; ++i)
	{
		vector<int> element(n, 0);
		Map.push_back(element);
	}

	//Map���� ���簢�� �κ��� -1ó��
	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y2; ++y) 
		{
			for (int x = x1; x < x2; ++x)
			{
				if (Map[y][x] == -1) continue;
				else Map[y][x] = -1;
			}
		}
	}

	Area area(Map, m, n);
	area.FindArea();
}