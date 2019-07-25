#include <cstdio>
#include <queue>

using namespace std;

int arr[2][200001];
int visited[2][200001];
int n, k;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%1d", &arr[0][i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%1d", &arr[1][i]);
	}
	for (int i = n+1; i <= 200000; i++) {
		arr[0][i] = arr[1][i] = 1;
	}

	queue<pair<int,int>> step;
	queue<pair<int, int>> q;
	q.push(make_pair(0, 1));
	visited[0][1] = 1;
	int cnt = 1;
	while (cnt <= n) {
		while (!q.empty()) {
			int l = q.front().first; int cur = q.front().second; q.pop();

			if (arr[l][cur + 1] == 1 && !visited[l][cur + 1]) {
				step.push(make_pair(l, cur + 1));
				visited[l][cur + 1] = 1;
			}
			if (arr[l][cur - 1] == 1 && arr[l][cur - 1] != -1 && !visited[l][cur - 1]) {
				step.push(make_pair(l, cur - 1));
				visited[l][cur - 1] = 1;
			}
			if (arr[(l + 1) % 2][cur + k] == 1 && !visited[(l + 1) % 2][cur + k]) {
				step.push(make_pair((l + 1) % 2, cur + k));
				visited[(l + 1) % 2][cur + k] = 1;
			}
		}		
		arr[0][cnt] = arr[1][cnt] = -1; cnt++;
		while (!step.empty()) {
			int l2 = step.front().first; int cur2 = step.front().second;
			if (cur2 >= n) { printf("1\n"); return 0; }
			if (arr[l2][cur2] == -1) {
				step.pop();
				continue;
			}
			q.push(step.front()); step.pop();
		}
		

	}
	printf("0\n");
	return 0;

}