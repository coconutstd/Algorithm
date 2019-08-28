#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
typedef vector<vector<vector<int>>> Box;
typedef tuple<int, int, int> Coordinate;

class Tomato
{
private:
	int m, n, h;
	const int dx[6] = { 0,0,-1,+1,0,0 };
	const int dy[6] = { +1,-1,0,0,0,0 };
	const int dz[6] = { 0,0,0,0,+1,-1 };
	Box& Data;
	queue<Coordinate>& q;
public:
	Tomato(Box& _box, queue<Coordinate>& _q, int _m, int _n, int _h) : Data(_box), m(_m), n(_n), h(_h), q(_q) {  }
	int Bfs();
	bool SearchMap();

};

int Tomato::Bfs()
{
	int day = 0;
	while (!q.empty())
	{
		int size = q.size();

		for (int i = 0; i < size; i++)
		{
			int x, y, z;
			tie(x, y, z) = q.front();
			q.pop();
			for (int i = 0; i < 6; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];
				if (0 <= nx && nx < m && 0 <= ny && ny < n && 0 <= nz && nz < h && Data[nz][ny][nx] == 0)
				{
					q.push(make_tuple(nx, ny, nz));
					Data[nz][ny][nx] = 1;
				}
			}
		}
		day++;
	}
	if (day == 0) { return 0; }
	else return day-1;
}

bool Tomato::SearchMap()
{
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				if (Data[i][j][k] == 0) return false;
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n, h;
	cin >> m >> n >> h;
	Box box;
	Box visited;
	queue<Coordinate> q;

	for (int i = 0; i < h; ++i)
	{
		vector<vector<int>> matrix;
		for (int j = 0; j < n; j++)
		{
			vector<int> element(m,0);
			matrix.push_back(element);
		}
		box.push_back(matrix);
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				int t;
				cin >> t;
				if (t == 1)
				{
					q.push(make_tuple(k, j, i));
				}
				box[i][j][k] = t;
			}
		}
	}
	Tomato tomato(box, q, m, n, h);
	int result = tomato.Bfs();

	if (tomato.SearchMap())
	{
		cout << result;
	}
	else
	{
		cout << "-1";
	}
}