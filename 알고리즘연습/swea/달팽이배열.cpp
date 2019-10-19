#include <stdio.h>
#include <vector>

#define vv vector<vector<int>>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {
		int n;
		scanf("%d", &n);
		vv arr;
		for (int i = 0; i < n; i++) {
			vector<int> element(n, 0);
			arr.push_back(element);
		}
		int rowStart=0, rowEnd=n-1, colStart=0, colEnd=n-1;
		int val = 1;
		while (rowStart <= rowEnd && colStart <= colEnd) {
			for (int i = colStart; i <= colEnd; i++) {
				arr[rowStart][i] = val++;
			}
			rowStart++;
			for (int i = rowStart; i <= rowEnd; i++) {
				arr[i][colEnd] = val++;
			}
			colEnd--;
			if(rowStart<=rowEnd)
			for (int i = colEnd; i >= colStart; i--) {
				arr[rowEnd][i] = val++;
			}
			rowEnd--;
			if(colStart<=colEnd)
			for (int i = rowEnd; i >= rowStart; i--) {
				arr[i][colStart] = val++;
			}
			colStart++;
		}
		printf("#%d\n", test_case);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", arr[i][j]);
			}
			puts("");
		}
	}
}