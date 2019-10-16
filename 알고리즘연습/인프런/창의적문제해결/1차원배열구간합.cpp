#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n,k;
	scanf_s_s("%d %d", &n, &k);

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		scanf_s_s("%d", &arr[i]);
	}

	int sum = 0;
	for (int i = 0; i < k; i++) {
		sum += arr[i];
	}
	int max = sum;
	for (int i = k; i < n; i++) {
		sum = sum + arr[i] - arr[i - k];
		if (max < sum) max = sum;
	}

	printf("%d\n", max);
}