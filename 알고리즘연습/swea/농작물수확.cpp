#include <stdio.h>
#include <vector>
using namespace std;

#define vv vector<vector<int>>

class Farm {
	vv &map;
	int n;
public:
	Farm(int _n, vv& _map) :n(_n), map(_map) {};
	int answer();
};

int Farm::answer() {
	int ans = 0;
	//별찍기 응용
	if (n == 0) return map[0][0];
	//위쪽
	for (int i = 0,j; i <= n / 2; i++) {
		for (j = n / 2 - i; j < n - n/2+i; j++) {
			ans += map[i][j];
		}
	}
	//아래쪽
	for (int i = n / 2 + 1,j; i < n; i++) {
		for (j = n/2 - (n-1-i); j <= n/2 + (n-1-i); j++) {
			ans += map[i][j];
		}
	}
	return ans;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {
		int n,i,j;
		scanf("%d", &n);
		vv map;
		for (i = 0; i < n; i++) {
			vector<int> element(n, 0);
			map.push_back(element);
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%1d", &map[i][j]);
			}
		}
		Farm farm(n, map);
		printf("#%d %d\n", test_case, farm.answer());
	}
}