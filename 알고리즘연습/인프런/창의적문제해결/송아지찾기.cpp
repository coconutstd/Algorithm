/*
송아지찾기

bfs의 상태트리탐색
*/
#include <stdio.h>
#include <queue>

using namespace std;

int ch[10001];
int d[3] = { -1,1,5 };
int main() {
	int s, e;
		
	scanf_s("%d %d", &s, &e);
	queue<int> q;
	ch[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			int cc = c + d[i];
			if (cc < 1 || cc >10000) continue;
			if (cc == e) {
				printf("%d\n", ch[c]);
				exit(0);
			}
			if (ch[cc] == 0) {
				ch[cc] = ch[c] + 1;
				
				q.push(cc);
			}
		}
	}

}