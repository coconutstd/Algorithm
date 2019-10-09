#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10001;
int parent[MAX];

struct Node {
	int v, e, weight;
	bool operator<(Node const &e) {
		return weight < e.weight;
	}
};

int find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		parent[y] = x;
	}
}

int N, E;

int main() {
	cin >> N >> E;
	vector<Node> data(E);
	for (int i = 0; i < E; i++) {
		cin >> data[i].v >> data[i].e >> data[i].weight;
	}
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	sort(data.begin(), data.end());
	int answer = 0;
	for (int i = 0; i < E; i++) {
		if (find(data[i].v) != find(data[i].e)) {
			answer += data[i].weight;
			merge(data[i].v, data[i].e);
		}
	}

	cout << answer;

	
}