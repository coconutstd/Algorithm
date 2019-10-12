/*
 프로그래머스 고득점 kit
 네트워크
 노드의 개수와 2차원 배열이 주어졌을 때 네트워크의 개수를 구하는 문제
 입력 : N = 3 , [[1, 1, 0], [1, 1, 0], [0, 0, 1]] 출력 : 2
 각 노드에 대해서 bfs를 수행하면서 새롭게 방문하는 노드가 있으면 answer 증가
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