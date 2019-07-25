#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	unordered_map<int, int> map;
	vector<tuple<int,int, int, int>> v;
	for (int i = 1; i <= 100; i++) {
		map[i*i*i] = i;
	}
	for (int i = 2; i <= 98; i++) {
		for (int j = i + 1; j <= 99; j++) {
			for (int k = j + 1; k <= 100; k++) {
				int key = (i*i*i) + (j*j*j) + (k*k*k);
				int res = map[key];
				if (res) {
					v.push_back(make_tuple(res, i, j, k));
				}
			}
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		int a, b, c, d;
		tie(a, b, c, d) = v[i];
		printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
	}
}