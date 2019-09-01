#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[8] = {-1,-1,+1,+1,+1,-1,0,0};
const int dy[8] = {-1,+1,-1,+1,0,0,+1,-1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector <vector<deque<int>>> tree;
	vector<vector<int>> plus;
	vector<vector<int>> map;
	int N,M,K;
	cin >> N >> M >> K;
	for (int i = 0; i <= N; ++i) {
		vector<deque<int>> element(N+1);
		vector<int> element2(N+1, 0);
		vector<int> element3(N+1, 5);
		tree.push_back(element);
		plus.push_back(element2);
		map.push_back(element3);
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> plus[i][j];
		}
	}
	for (int i = 0; i < M; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			sort(tree[i][j].begin(), tree[i][j].end());
		}
	}

	while (K--) {
		//1 �� : �ڽ��� ���̸�ŭ ����� �԰� ���� 1���� �������ϸ� ����
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (tree[i][j].size() != 0) {
					int size = tree[i][j].size();
					queue<int> dead;
					for (int k = 0; k < size; ++k) {
						int age = tree[i][j].front();
						tree[i][j].pop_front();
						if (age <= map[i][j]) {
							map[i][j] -= age;
							tree[i][j].push_back(age + 1);
						}
						else {
							dead.push(age);
						}
					}
					//2 ���� : ���� ������ �ڽ��� ���� ������ 2�� ������� �����ش�
					while (!dead.empty()) {
						map[i][j] += dead.front() / 2;
						dead.pop();
					}
				}
			}
		}

		//3 ���� : ���̰� 5�� ����� ��� 8�������� ���̰� 1�� ���� ����

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (tree[i][j].size() != 0) {
					int size = tree[i][j].size();
					for (int k = 0; k < size; ++k) {
						if (tree[i][j][k] % 5 == 0) {
							for (int p = 0; p < 8; ++p) {
								int nx = i + dx[p];
								int ny = j + dy[p];
								if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
									tree[nx][ny].push_front(1);
								}
							}
						}
					}
				}
			}
		}

		//4 �ܿ� : �κ��� ����� �߰��Ѵ�

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				map[i][j] += plus[i][j];
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			sum += tree[i][j].size();
		}
	}
	cout << sum;
}