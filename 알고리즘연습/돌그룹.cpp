#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, unordered_map<int,unordered_map<int, bool> > > visited;

int bfs(vector<int>& v) {
	queue<vector<int>> q;
	sort(v.begin(), v.end());
	q.push(v);
	visited[v[0]][v[1]][v[2]] = 1;
	while (!q.empty()) {

		vector<int> here = q.front(); q.pop();
		vector<int> copy = here;
		if (here[0] == here[1] && here[1] == here[2]) { return 1; }
		for (int i = 0; i < 2; i++) {
			for (int j = i + 1; j < 3; j++) {
				if (here[i] > here[j]) {
					here[i] = here[i] - here[j];
					here[j] += here[j];
				}
				else {
					here[j] = here[j] - here[i];
					here[i] += here[i];
				}
				sort(here.begin(), here.end());
				if (visited[here[0]][here[1]][here[2]] == 0) {
					q.push(here);
					visited[here[0]][here[1]][here[2]] = 1;
				}
				here = copy;
			}
		}
	}

	return 0;
}

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	vector<int> orig;
	orig.push_back(a); orig.push_back(b); orig.push_back(c);
	printf("%d\n", bfs(orig));

}