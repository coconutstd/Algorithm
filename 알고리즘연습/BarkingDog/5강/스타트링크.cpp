/*
 ���� 5014 �� : ��ŸƮ��ũ

 �ذ� : �ΰ��� �������� �̵�����. Bfs������ ��ǥ���� ���� �� �� ���� ���� �ּ�Ƚ���� ����
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	vector<int> visited(F+1, 0);
	visited[S] = -1;

	queue<int> Q;
	Q.push(S);
	int cnt = 0;
	int ans = -1;
	if (G <1 || G > F) {
		cout << "use the stairs";
	}
	else {
		while (!Q.empty()) {
			int size = Q.size();
			for (int i = 0; i < size; i++) {
				int now = Q.front();
				Q.pop();
				if (now == G) {
					ans = cnt;
				}
				int up = now + U;
				int down = now - D;
				if (up <= F && visited[up] != -1) {
					Q.push(up);
					visited[up] = -1;
				}
				if (down > 0 && visited[down] != -1) {
					Q.push(down);
					visited[down] = -1;
				}
			}
			if (ans != -1) break;
			cnt++;
		}
	}

	if (ans != -1) {
		cout << ans;
	}
	else {
		cout << "use the stairs";
	}

}