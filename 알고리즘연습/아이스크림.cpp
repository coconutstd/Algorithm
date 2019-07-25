#include <iostream>
#include <vector>
using namespace std;
int n, m,cnt;
int arr[201][201];

void dfs(int ice, vector<int> list) {

	if (list.size() == 3) {
		cnt++;
		return;
	}

	for (int i = ice + 1; i <= n; i++) {
		if (!arr[ice][i]) {
			list.push_back(i);
			if (list.size() >= 2) {
				if (!arr[list[0]][i]) {
					dfs(i, list);
				}
			}else dfs(i, list);
			list.pop_back();
		}
	}

}

int main() {
	cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	dfs(0,v);
	cout << cnt << '\n';
}

