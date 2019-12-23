#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int sudoku[9][9];
vector<pair<int, int>> coord;
vector<tuple<int, int, int>> ans;

bool square(int i, int j) {
	bool ret = true;
	int row = 3 * (i / 3);
	int col = 3 * (j / 3);
	for (int r = row; r < row + 3; r++) {
		for (int c = col; c < col + 3; c++) {
			if (i == r && j == c) continue;
			if (sudoku[r][c] == sudoku[i][j]) {
				ret = false;
			}
		}
	}
	return ret;
}

bool rowValid(int i, int j) {
	bool ret = true;
	for (int row = 0; row < 9; row++) {
		if (row == i) continue;
		if (sudoku[i][j] == sudoku[row][j]) {
			ret = false;
		}
	}
	return ret;
}

bool colValid(int i, int j) {
	bool ret = true;
	for (int col = 0; col < 9; col++) {
		if (col == j) continue;
		if (sudoku[i][j] == sudoku[i][col]) {
			ret = false;
		}
	}
	return ret;
}

bool isValid(int i, int j) {
	if (!square(i, j) || !rowValid(i, j) || !colValid(i, j)) {
		coord.push_back(make_pair(i, j));
		return false;
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		int k;
		cin >> k;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> sudoku[i][j];
			}
		}

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				isValid(i, j);
			}
		}

		for (int i = 0; i < coord.size(); i++) {
			cout << coord[i].first+1 << " " << coord[i].second+1 << "\n";
		}

		for (int i = 0; i < coord.size(); i++) {
			int check[3][10] = { {0,} };
			for (int j = 0; j < 9; j++) {
				check[0][sudoku[coord[i].first][i]]++;
			}
			for (int j = 0; j < 9; j++) {
				check[1][sudoku[j][coord[i].second]]++;
			}
			int row = 3 * (coord[i].first / 3);
			int col = 3 * (coord[i].second / 3);
			for (int r = row; r < row + 3; r++) {
				for (int c = col; c < col + 3; c++) {
					check[2][sudoku[r][c]]++;
				}
			}

			for (int l = 1; l <= 9; l++) {
				if (check[0][l] == 0 && check[1][l] == 0 && check[2][l] == 0) {
					ans.push_back(make_tuple(coord[i].first, coord[i].second, l));
				}
			}
		}

		cout << "#" << t << " ";
		for (auto val : ans) {
			int x, y, z;
			tie(x, y, z) = val;
			cout << x + 1 << " " << y + 1 << " " << z << " ";
		}
		cout << "\n";
		coord.resize(0);
		ans.resize(0);
	}
}