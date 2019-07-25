#include <cstdio>
#include <list>
#include <vector>
using namespace std;

int main() {
	int n, k;

	scanf("%d %d", &n, &k);
	list<int> jose;
	for (int i = 1; i <= n; i++) {
		jose.push_back(i);
	}
	vector<int> ans;
	list<int>::iterator lt = jose.begin();
	while (jose.size() != 0) {
		for (int i = 0; i < k - 1; i++) {
			lt++;
			if (lt == jose.end()) lt = jose.begin();
		}
		ans.push_back(*lt);
		lt = jose.erase(lt);
		if (lt == jose.end()) lt = jose.begin();
	}
	printf("<");
	for (vector<int>::iterator vlt = ans.begin(); vlt != ans.end(); vlt++) {
		if (vlt == ans.end() - 1) { printf("%d>\n",*vlt); break; }
		printf("%d, ", *vlt);
	}
}