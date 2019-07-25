#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int ans[9];
vector<int> input;

void permutation(int index, int start) {
	if (index == M) {
		for (int i = 0; i < M; i++)printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = start; i < N; i++) {
		ans[index] = input[i];
		permutation(index + 1, i + 1);
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
	permutation(0, 0);

}