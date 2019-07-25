#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int ans[9];
bool check[9];
vector<int> input;

void permutation(int index) {
	if (index == M) {
		for (int i = 0; i < M; i++) printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++) {
		if (check[i]) continue;
		ans[index] = input[i];
		check[i] = true;
		permutation(index + 1);
		check[i] = false;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		input.push_back(temp);
	}
	sort(input.begin(), input.end());
	permutation(0);

}