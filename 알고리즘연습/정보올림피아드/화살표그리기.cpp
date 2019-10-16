/*
화살표 그리기
정렬해준후 푸는 것이 포인트
*/

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	/*
	0 1
	3 1
	5 1
	1 2
	4 2
	*/
	vector<vector<int>> p(n+1);
	// 1 -> 0 , 3, 5 
	// 2 -> 1 , 4
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		p[b].push_back(a);
	}
	for (int i = 0; i <= n; i++) {
		if(p[i].size() != 0)
		sort(p[i].begin(), p[i].end());
	}
	long long sum = 0;
	for (int i = 0; i <= n; i++) {
		if(p[i].size()!=0)
		for (int j = 0; j < p[i].size(); j++) {
			if (j == 0) {
				// 3 - 0
				sum += p[i][j + 1] - p[i][j];
				continue;
			}
			else if (j == p[i].size() - 1) {
				// 5 - 3
				sum += p[i][j] - p[i][j - 1];
				continue;
			}
			sum += min(p[i][j] - p[i][j - 1], p[i][j + 1] - p[i][j]);
		}
	}
	printf("%lld\n", sum);
}