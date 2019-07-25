#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> seven;
int input[9];
bool check[9];
int cnt;
int smallest;
void recursive(int n, vector<int>& picked, int toPick) {
	if (toPick ==0) {
		for (int i = 0; i < picked.size(); i++) printf("%d ", picked[i]);
		printf("\n");
		return;
	}
	//선택할 수 있는 것 중 가장 작은 거 선택하기
	if (picked.empty()) smallest = 0;
	else {
		for (int i = 0; i < n; i++) {
			if (check[i] == false) smallest = i;
		}
	}
	for (int next = smallest; next < n; next++) {
		picked.push_back(input[next]);
		check[next] = true;
		recursive(n, picked, toPick - 1);
		picked.pop_back();
		check[next] = false;
	}
}

int main() {
	for (int i = 0; i < 9; i++) scanf("%d", &input[i]);
	recursive(9, seven, 7);


}