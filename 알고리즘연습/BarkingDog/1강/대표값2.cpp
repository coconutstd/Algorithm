#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int arr[5],sum =0;
	for (int i = 0; i < 5; i++) {
		scanf_s_s("%d", &arr[i]);
		sum += arr[i];
	}
	sort(arr, arr + 5);
	printf("%d\n%d", sum / 5, arr[2]);
}