#include <stdio.h>
#include <vector>

#define v vector<int> 
#define vv vector<vector<int>>


using namespace std;

class Rotator {
	int n;
	int index;
	vv& map;
	vv& storage;
public:
	Rotator(int _n, vv& _map, vv& _storage) :n(_n), map(_map),storage(_storage), index(0) {
		rotate();
		rotate();
		rotate();
	};

	void print();

private:
	void rotate();
};


void Rotator::rotate() {
	vv copy = map;
	int i,j,k;
	int colStart = 0, colEnd = n -1, rowStart=0,rowEnd = n-1;
	while (rowStart <= rowEnd && colStart <= colEnd) {
		for (i = colStart,j = rowStart; i <= colEnd; i++,j++) {
			map[j][colEnd] = copy[rowStart][i];
		}
		for (i = rowStart, j = colEnd; i <= rowEnd; i++,j--) {
			map[rowEnd][j] = copy[i][colEnd];
		}
		for (i = colEnd, j = rowEnd; i >= colStart; i--, j--) {
			map[j][colStart] = copy[rowEnd][i];
		}
		for (i = rowEnd, j = colStart; i >= rowStart; i--, j++) {
			map[rowStart][j] = copy[i][rowStart];
		}
		rowStart++, rowEnd--, colStart++, colEnd--;
	}

	for (i = 0,k=0; i < n; i++) {
		for (j = 0; j < n; j++) {
			storage[index][k++] = map[i][j];
			if (k == n*n) k = 0;
		}
	}	
	index++;


}

void Rotator::print() {
	int i, j, k,offset;
	for (i = 0, offset = 0; i < n; i++, offset += n) {
		for (j = 0; j < 3; j++) {
			for (k = offset; k < offset + n; k++) {
				printf("%d", storage[j][k]);
			}
			printf(" ");
		}
		puts("");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int test_case = 1; test_case <= t; test_case++) {
		int n,i,j;
		scanf("%d", &n);
		vv map(n,v(n));
		vv storage(3, v(n * n));
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		Rotator rotator(n, map,storage);
		printf("#%d\n", test_case);
		rotator.print();
	}
}