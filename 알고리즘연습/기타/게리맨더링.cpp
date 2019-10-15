/*
 게리맨더링

 도시의 인구수를 입력받아 두 선거 그룹으로 나누었을 때 두 선거구 인구수 차이의 최소값은?

 next_permutation으로 두 그룹으로 나누는 모든 경우를 만들고 dfs를 통해 이어져 있는지 확인

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int adj[11][11],p[11],visit[11];

int dfs(int v, vector<int>& area, int type) {
	int cnt = 1;
	visit[v] = true;
	for (int i = 1; i <= n; i++) {
		if (area[i - 1] == type && adj[v][i] && !visit[i]) {
			cnt += dfs(i, area, type);
		}
	}
	return cnt;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	for (int i = 1, t; i <= n; i++) {
		cin >> t;
		for (int j = 0, temp; j < t; j++) {
			cin >> temp;
			adj[i][temp] = 1;
		}
	}

	int ans = 987654321;
	// 011111 ~ 000001 로 선거구 나누기
	for (int i = 1; i <= n - 1; i++) {
		vector<int> area(i, 0);
		for (int j = i + 1; j <= n; j++) {
			area.push_back(1);
		}
		do
		{
			int idx1 = -1;
			int idx2 = -1;
			for (int k = 0; k < area.size(); k++) {
				if (area[k] == 0) idx1 = k;
				else idx2 = k;
				if (idx1 != -1 && idx2 != -1) break;
			}

			int cnt1, cnt2;

			memset(visit, 0, sizeof(visit));
			cnt1 = dfs(idx1 + 1, area, 0);
			memset(visit, 0, sizeof(visit));
			cnt2 = dfs(idx2 + 1, area, 1);
			
			if (cnt1 == i && cnt2 == n - i) {
				int res1=0, res2=0;
				for (int k = 0; k < area.size(); k++) {
					if (area[k] == 0) {
						res1 += p[k + 1];
					}
					else {
						res2 += p[k + 1];
					}
				}

				int sub = abs(res1 - res2);
				if (ans > sub) {
					ans = sub;
				}
			}
		} while (next_permutation(area.begin(),area.end()));
	}

	if (ans == 987654321) cout << -1;
	else cout << ans;

}