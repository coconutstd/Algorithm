/*
 ���α׷��ӽ� ����� kit
 ��Ʈ��ũ
 ����� ������ 2���� �迭�� �־����� �� ��Ʈ��ũ�� ������ ���ϴ� ����
 �Է� : N = 3 , [[1, 1, 0], [1, 1, 0], [0, 0, 1]] ��� : 2
 �� ��忡 ���ؼ� bfs�� �����ϸ鼭 ���Ӱ� �湮�ϴ� ��尡 ������ answer ����
*/

#include <string>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& c, int p, int n, vector<int>& visited) {
	queue<int> q;
	q.push(p);
	visited[p] = 1;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front();
			q.pop();
			for (int j = 0; j < n; j++) {
				if (x == j) continue;
				if (c[x][j] == 1 && visited[j] == 0) {
					q.push(j);
					visited[j] = 1;
				}
			}
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	vector<int> visited(n, 0);
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			answer++;
			bfs(computers, i, n, visited);
		}
	}

	return answer;
}