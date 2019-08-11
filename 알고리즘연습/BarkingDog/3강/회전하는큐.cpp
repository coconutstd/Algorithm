#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int minOperation(deque<int>& dq, int num) {
	int left, right;
	for (int i = 0; i < dq.size(); i++) {
		if (num == dq[i]) {
			left = i;
			right = dq.size() - left;
		}
	}
	if (left < right) {
		for (int i = 0; i < left; i++) {
			int t = dq.front(); dq.pop_front();
			dq.push_back(t);
		}
		dq.pop_front();
		return left;
	}
	else {
		for (int i = 0; i < right; i++) {
			int t = dq.back(); dq.pop_back();
			dq.push_front(t);
		}
		dq.pop_front();
		return right;
	}
	
}

int main() {
	deque<int> dq;
	int n,m,ans=0;
	scanf("%d %d", &n,&m);
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		if (num == dq.front()) {
			dq.pop_front();
		}
		else {
			ans += minOperation(dq, num);
		}
	}
	printf("%d\n", ans);
}