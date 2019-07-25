#include <iostream>
#include <vector>
using namespace std;

vector<int> orig;
int N,ans = 0;

void dfs(int size, int sum, vector<int> e) {
	if (size == 2) {
		if (sum > ans) {
			ans = sum;
		}
		return;
	}

	for (vector<int>::iterator it = e.begin() + 1; it != e.end() - 1;) {
		int t = *it;
		int energy = *(it - 1) * *(it + 1);
		it = e.erase(it);
		dfs(e.size(), sum + energy, e);
		it = e.insert(it, t);
		it++;
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		orig.push_back(t);
	}
	dfs(orig.size(),0, orig);
	cout << ans << endl;

}