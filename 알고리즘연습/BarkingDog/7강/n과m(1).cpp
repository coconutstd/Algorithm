#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a, ind;
	for (int i = 1; i <= n; i++) {
		a.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		ind.push_back(0);
	}
	for (int i = 0; i < n - m; i++) {
		ind.push_back(1);
	}
	sort(ind.begin(), ind.end());
	do
	{
		for (int i = 0; i < n; i++) {
			if (ind[i] == 0) {
				cout << a[i] << " ";
			}
		}
		cout << endl;
	} while (next_permutation(ind.begin(),ind.end()));
}