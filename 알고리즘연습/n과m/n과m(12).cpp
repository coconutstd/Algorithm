#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int ans[10];
int number[10];
vector<vector<int>> plist;

void permutation(int index, int start) {
	if (index == M) {
		vector<int> temp;
		for (int i = 0; i < M; i++) {
			temp.push_back(number[ans[i]]);
		}
		plist.push_back(temp);
		return;
	}
	for (int i = start; i < N; i++) {
		ans[index] = i;
		permutation(index + 1, i);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &number[i]);
	sort(number, number + N);
	permutation(0, 0);
	sort(plist.begin(), plist.end());
	plist.erase(unique(plist.begin(), plist.end()), plist.end());
	for (auto& per : plist) {
		for (int i = 0; i < M; i++) {
			printf("%d ", per[i]);
		}
		printf("\n");
	}

}