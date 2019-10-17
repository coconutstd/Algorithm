#include <stdio.h>
#include <vector>

#define vv vector<vector<int>>

using namespace std;


int main() {
	for (int test_case = 1; test_case <= 10; test_case++) {
		int tnum, sum = 0,sum2=0;
		scanf("%d", &tnum);
		vv arr, sarr;
		for (int i = 0; i < 100; i++) {
			vector<int> element(100, 0);
			arr.push_back(element);
		}
		int max = -1;
		for (int i = 0; i < 100; i++) {
			sum = 0;
			for (int j = 0; j < 100; j++) {
				scanf("%d", &arr[i][j]);
				sum += arr[i][j];
				if (i == j) sum2 += arr[i][j];
			}
			if (max < sum) max = sum;
		}
		max = (max > sum2) ? max : sum2;

		sum2 = sum = 0;

		for (int i = 99; i >= 0; i--) {
			sum = 0;
			for (int j = 0; j <100; j++) {
				sum += arr[j][i];
				if (i + j == 99)sum2 += arr[j][i];
			}
			if (max < sum) max = sum;
		}
		max = (max > sum2) ? max : sum2;

		printf("#%d %d\n", test_case, max);
	}
}