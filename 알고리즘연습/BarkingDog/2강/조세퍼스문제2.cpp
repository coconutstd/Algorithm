#include <cstdio>
#include <queue>
using namespace std;

class Jose
{
	int n, k;
public:
	Jose(int _n, int _k) :n(_n), k(_k) {};
	void startGame();
};

void Jose::startGame() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	printf("<");
	int o = k;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		if (o == 1) {
			o = k;
			if (q.empty()) { printf("%d>\n", t); break; }
			printf("%d, ", t);
			continue;
		}
		q.push(t); o--;
	}
}

int main() {

	int n, k;
	scanf_s_s("%d %d", &n, &k);
	Jose jose(n, k);
	jose.startGame();
	
}