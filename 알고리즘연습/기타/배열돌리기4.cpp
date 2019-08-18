#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct RotateInfo
{
	int r, c, s;
public:
	RotateInfo(int _r, int _c, int _s) {
		r = _r, c = _c, s = _s;
	}
};

class Matrix
{
private:
	vector<vector<int>> &arr;
	vector<RotateInfo> rotateInfo;
	int NeedToRotate;

	int row, col;

public:
	Matrix(vector<vector<int>>& _arr, int _row, int _col);
	void PushRotateInfo(RotateInfo info);
	RotateInfo& GetRotateInfo(int index) { return rotateInfo[index]; }
	void Rotate(RotateInfo& info);
	int MinRowValue(vector<vector<int>>& inputArr);
	void SetArray(vector<vector<int>>& orig);
};

Matrix::Matrix(vector<vector<int>>& _arr, int _row, int _col): arr(_arr), row(_row), col(_col){}


void Matrix::PushRotateInfo(RotateInfo info)
{
	rotateInfo.push_back(info);
}

void Matrix::Rotate(RotateInfo& _info)
{
	int r = _info.r, c = _info.c, s = _info.s;
	int iter = s;
	int row = r - s, col = c - s;
	while (iter--)
	{
		int tmp1 = arr[row][col], tmp2;
		for (col; col < c + s; col++)
		{
			tmp2 = arr[row][col + 1];
			arr[row][col + 1] = tmp1;
			tmp1 = tmp2;
		}
		for (row; row < r + s; row++)
		{
			tmp2 = arr[row + 1][col];
			arr[row + 1][col] = tmp1;
			tmp1 = tmp2;
		}
		for (col; col > c - s; col--)
		{
			tmp2 = arr[row][col - 1];
			arr[row][col - 1] = tmp1;
			tmp1 = tmp2;
		}
		for (row; row > r - s; row--)
		{
			tmp2 = arr[row - 1][col];
			arr[row - 1][col] = tmp1;
			tmp1 = tmp2;
		}
		row++; col++; s--;
	}
}

int Matrix::MinRowValue(vector<vector<int>>& inputArr)
{
	int min = 500000, sum;
	for (int r = 1; r <= row; r++) {
		sum = 0;
		for (int c = 1; c <= col; c++) {
			sum += inputArr[r][c];
		}
		if (min > sum) min = sum;
	}
	return min;
}

void Matrix::SetArray(vector<vector<int>>& orig)
{
	arr = orig;
}

int main() {
	int row, col, k;
	cin >> row >> col >> k;
	vector<vector<int>> arr;
	vector<vector<int>> orig;
	
	for (int i = 0; i <= row; i++) {
		vector<int> element(col+1);
		arr.push_back(element);
	}

	for (int r = 1; r <= row; r++) {
		for (int c = 1; c <= col; c++) {
			cin >> arr[r][c];
		}
	}
	orig = arr;
	Matrix matrix(arr, row, col);
	int r, c, s;
	for (int i = 0; i < k; i++) {
		cin >> r >> c >> s;
		matrix.PushRotateInfo(RotateInfo(r, c, s));
	}
	
	vector<int> Order;
	for (int i = 0; i < k; i++) {
		Order.push_back(i);
	}
	int min = 500000;
	do
	{
		for (int i = 0; i < Order.size(); i++) {
			matrix.Rotate(matrix.GetRotateInfo(Order[i]));
		}
		int result = matrix.MinRowValue(arr);
		if (min > result) {
			min = result;
		}

		matrix.SetArray(orig);
		
	} while (next_permutation(Order.begin(),Order.end()));

	cout << min;
}