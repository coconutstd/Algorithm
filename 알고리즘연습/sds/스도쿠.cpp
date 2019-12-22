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
	if (!square(i, j) && !rowValid(i, j) && !colValid(i, j)) {
		coord.push_back(make_pair(i, j));
		return false;
	}
	return true;
}

bool correctValid(int i, int j) {
	if (square(i, j) && colValid(i, j) && rowValid(i, j)) {
		return true;
	}
	else return false;
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

		if (k == 1) {
			for (int i = 1; i <= 9; i++) {
				sudoku[coord[0].first][coord[0].second] = i;
				if (correctValid(coord[0].first, coord[0].second)) {
					ans.push_back(make_tuple(coord[0].first, coord[0].second, sudoku[coord[0].first][coord[0].second]));
				}

			}
		}
		else if (coord.size() == 2 && k == 2) {
			bool check = false;
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= 9; j++) {
					sudoku[coord[0].first][coord[0].second] = i;
					sudoku[coord[1].first][coord[1].second] = j;
					if (correctValid(coord[0].first, coord[0].second) && correctValid(coord[1].first, coord[1].second)) {
						ans.push_back(make_tuple(coord[0].first, coord[0].second, sudoku[coord[0].first][coord[0].second]));
						ans.push_back(make_tuple(coord[1].first, coord[1].second, sudoku[coord[1].first][coord[1].second]));
						check = true;
						break;
					}
				}
				if (check) break;
			}
		}
		else if (k == 3) {
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= 9; j++) {
					for (int l = 1; l <= 9; l++) {
						sudoku[coord[0].first][coord[0].second] = i;
						sudoku[coord[1].first][coord[1].second] = j;
						sudoku[coord[2].first][coord[2].second] = l;
						if (correctValid(coord[0].first, coord[0].second) && correctValid(coord[1].first, coord[1].second) && correctValid(coord[2].first, coord[2].second)) {
							ans.push_back(make_tuple(coord[0].first, coord[0].second, sudoku[coord[0].first][coord[0].second]));
							ans.push_back(make_tuple(coord[1].first, coord[1].second, sudoku[coord[1].first][coord[1].second]));
							ans.push_back(make_tuple(coord[2].first, coord[2].second, sudoku[coord[2].first][coord[2].second]));
						}
					}

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