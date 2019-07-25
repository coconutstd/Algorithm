#include <iostream>
#include <vector>
using namespace std;

class Minki
{
	vector<pair<int,int>> &source;
	int N, L,max=0;

public:
	Minki(vector<pair<int, int>> &src, int _N, int _L) :source(src), N(_N), L(_L) {};
	int get_score(int, int, int);
};

int Minki::get_score(int i,int cal, int sum) {
	if (i + 1 > N) {
		if (cal <= L && sum > max) { max = sum; }
		return 0;
	}
	this->get_score(i + 1, cal, sum);
	this->get_score(i + 1, cal + this->source[i].second, sum + this->source[i].first);

	return max;
}

int main()
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<pair<int, int>> v;
		int n, l;
		cin >> n >> l;
		for (int i = 0; i < n; i++) {
			int item, cal;
			cin >> item >> cal;
			v.push_back(make_pair(item, cal));
		}
		Minki minki(v,n,l);
		cout << minki.get_score(0, 0,0) << endl;

	}
	return 0;
}