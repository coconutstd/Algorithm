#include <iostream>
#include <vector>
using namespace std;

int cube[6][3][3];

void rotate(int c) {
	switch (c)
	{
	case 1: 
	{
		int order[5] = { 0,3,2,1,0 };
		int temp[3] = { 0, };
		for (int i = 0; i < 3; i++) {
			cube[order[i + 1]][0][0] = cube[order[i]][0][0];
			cube[order[i + 1]][1][0] = cube[order[i]][1][0];
			cube[order[i + 1]][2][0] = cube[order[i]][2][0];
			temp[0] = cube[order[i + 2]][0][0];
			temp[1] = cube[order[i + 2]][1][0];
			temp[2] = cube[order[i + 2]][2][0];
		}
		cube[0][0][0] = temp[0];
		cube[0][1][0] = temp[1];
		cube[0][2][0] = temp[2];

		//시계반대방향회전
		for (int k = 0; k < 2; k++) {
			int col = 0, row = 0, tmp, tmp2,i=4;
			for (row; row < 2; row++) {
				tmp = cube[i][row + 1][col];
				cube[i][row + 1][col] = tmp;
			}
			for (col; col < 2; col++) {
				tmp2 = cube[i][row][col + 1];
				cube[i][row][col + 1] = cube[i][row][col];
				tmp = tmp2;
			}
			for (row; row > 0; row--) {
				tmp2 = cube[i][row - 1][col];
				cube[i][row - 1][col] = tmp;
				tmp = tmp2;
			}
			for (col; col > 0; col--) {
				tmp2 = cube[i][row][col - 1];
				cube[i][row][col - 1] = tmp;
				tmp = tmp2;
			}
		}
		break;
	}
	case 2:
	{
		int order[5] = { 0, 3, 2, 1, 0 };
		int temp[3] = { 0, };
		for (int i = 0; i < 3; i++) {
			cube[order[i + 1]][0][1] = cube[order[i]][0][1];
			cube[order[i + 1]][1][1] = cube[order[i]][1][1];
			cube[order[i + 1]][2][1] = cube[order[i]][2][1];
			temp[0] = cube[order[i + 2]][0][1];
			temp[1] = cube[order[i + 2]][1][1];
			temp[2] = cube[order[i + 2]][2][1];
		}
		cube[0][0][1] = temp[0];
		cube[0][1][1] = temp[1];
		cube[0][2][1] = temp[2];
		break;
	}
	case 3:
	{
		int order[5] = { 0, 3, 2, 1, 0 };
		int temp[3] = { 0, };
		for (int i = 0; i < 3; i++) {
			cube[order[i + 1]][0][2] = cube[order[i]][0][2];
			cube[order[i + 1]][1][2] = cube[order[i]][1][2];
			cube[order[i + 1]][2][2] = cube[order[i]][2][2];
			temp[0] = cube[order[i + 2]][0][2];
			temp[1] = cube[order[i + 2]][1][2];
			temp[2] = cube[order[i + 2]][2][2];
		}
		cube[0][0][2] = temp[0];
		cube[0][1][2] = temp[1];
		cube[0][2][2] = temp[2];
		//시계방향회전
		for (int k = 0; k < 2; k++) {
			int col = 0, row = 0, tmp, tmp2, i = 5;
			for (col; col < 2; col++) {
				tmp = cube[i][row][col + 1];
				cube[i][row][col + 1] = cube[i][row][col];
			}
			for (row; row < 2; row++) {
				tmp2 = cube[i][row + 1][col];
				cube[i][row + 1][col] = tmp;
				tmp = tmp2;
			}
			for (col; col > 0; col--) {
				tmp2 = cube[i][row][col - 1];
				cube[i][row][col - 1] = tmp;
				tmp = tmp2;
			}
			for (row; row > 0; row--) {
				tmp2 = cube[i][row - 1][col];
				cube[i][row - 1][col] = tmp;
				tmp = tmp2;
			}
		}
		break;
	}
	case 4:
	{
		int order[5] = { 0, 1, 2, 3, 0 };
		int temp[3] = { 0, };
		for (int i = 0; i < 3; i++) {
			cube[order[i + 1]][0][0] = cube[order[i]][0][0];
			cube[order[i + 1]][1][0] = cube[order[i]][1][0];
			cube[order[i + 1]][2][0] = cube[order[i]][2][0];
			temp[0] = cube[order[i + 2]][0][0];
			temp[1] = cube[order[i + 2]][1][0];
			temp[2] = cube[order[i + 2]][2][0];
		}
		cube[0][0][0] = temp[0];
		cube[0][1][0] = temp[1];
		cube[0][2][0] = temp[2];

		//시계방향회전
		for (int k = 0; k < 2; k++) {
			int col = 0, row = 0, tmp, tmp2, i = 4;
			for (col; col < 2; col++) {
				tmp = cube[i][row][col + 1];
				cube[i][row][col + 1] = cube[i][row][col];
			}
			for (row; row < 2; row++) {
				tmp2 = cube[i][row + 1][col];
				cube[i][row + 1][col] = tmp;
				tmp = tmp2;
			}
			for (col; col > 0; col--) {
				tmp2 = cube[i][row][col - 1];
				cube[i][row][col - 1] = tmp;
				tmp = tmp2;
			}
			for (row; row > 0; row--) {
				tmp2 = cube[i][row - 1][col];
				cube[i][row - 1][col] = tmp;
				tmp = tmp2;
			}
		}
		break;
	}
	case 5:
	{
		int order[5] = { 0, 1, 2, 3, 0 };
		int temp[3] = { 0, };
		for (int i = 0; i < 3; i++) {
			cube[order[i + 1]][0][1] = cube[order[i]][0][1];
			cube[order[i + 1]][1][1] = cube[order[i]][1][1];
			cube[order[i + 1]][2][1] = cube[order[i]][2][1];
			temp[0] = cube[order[i + 2]][0][1];
			temp[1] = cube[order[i + 2]][1][1];
			temp[2] = cube[order[i + 2]][2][1];
		}
		cube[0][0][1] = temp[0];
		cube[0][1][1] = temp[1];
		cube[0][2][1] = temp[2];
		break;
	}
	case 6:
	{
		int order[5] = { 0, 1, 2, 3, 0 };
		int temp[3] = { 0, };
		for (int i = 0; i < 3; i++) {
			cube[order[i + 1]][0][2] = cube[order[i]][0][2];
			cube[order[i + 1]][1][2] = cube[order[i]][1][2];
			cube[order[i + 1]][2][2] = cube[order[i]][2][2];
			temp[0] = cube[order[i + 2]][0][2];
			temp[1] = cube[order[i + 2]][1][2];
			temp[2] = cube[order[i + 2]][2][2];
		}
		cube[0][0][2] = temp[0];
		cube[0][1][2] = temp[1];
		cube[0][2][2] = temp[2];
		//시계반대방향회전
		for (int k = 0; k < 2; k++) {
			int col = 0, row = 0, tmp, tmp2, i = 5;
			for (row; row < 2; row++) {
				tmp = cube[i][row + 1][col];
				cube[i][row + 1][col] = tmp;
			}
			for (col; col < 2; col++) {
				tmp2 = cube[i][row][col + 1];
				cube[i][row][col + 1] = cube[i][row][col];
				tmp = tmp2;
			}
			for (row; row > 0; row--) {
				tmp2 = cube[i][row - 1][col];
				cube[i][row - 1][col] = tmp;
				tmp = tmp2;
			}
			for (col; col > 0; col--) {
				tmp2 = cube[i][row][col - 1];
				cube[i][row][col - 1] = tmp;
				tmp = tmp2;
			}
		}
		break;
	}
	case 7:
	{
		int order[5] = { 1, 4, 3, 5, 1 };
		int temp[3] = { 0, };
		for (int i = 0; i < 3; i++) {
			cube[order[i + 1]][0][0] = cube[order[i]][0][0];
			cube[order[i + 1]][0][1] = cube[order[i]][0][1];
			cube[order[i + 1]][0][2] = cube[order[i]][0][2];
			temp[0] = cube[order[i + 2]][0][0];
			temp[1] = cube[order[i + 2]][0][1];
			temp[2] = cube[order[i + 2]][0][2];
		}
		cube[1][0][0] = temp[0];
		cube[1][0][1] = temp[1];
		cube[1][0][2] = temp[2];
		//시계방향회전
		for (int k = 0; k < 2; k++) {
			int col = 0, row = 0, tmp, tmp2, i = 0;
			for (col; col < 2; col++) {
				tmp = cube[i][row][col + 1];
				cube[i][row][col + 1] = cube[i][row][col];
			}
			for (row; row < 2; row++) {
				tmp2 = cube[i][row + 1][col];
				cube[i][row + 1][col] = tmp;
				tmp = tmp2;
			}
			for (col; col > 0; col--) {
				tmp2 = cube[i][row][col - 1];
				cube[i][row][col - 1] = tmp;
				tmp = tmp2;
			}
			for (row; row > 0; row--) {
				tmp2 = cube[i][row - 1][col];
				cube[i][row - 1][col] = tmp;
				tmp = tmp2;
			}
		}
		break;
	}
	case 8:
	{
		int order[5] = { 1, 4, 3, 5, 1 };
		int temp[3] = { 0, };
		for (int i = 0; i < 3; i++) {
			cube[order[i + 1]][1][0] = cube[order[i]][1][0];
			cube[order[i + 1]][1][1] = cube[order[i]][1][1];
			cube[order[i + 1]][1][2] = cube[order[i]][1][2];
			temp[0] = cube[order[i + 2]][1][0];
			temp[1] = cube[order[i + 2]][1][1];
			temp[2] = cube[order[i + 2]][1][2];
		}
		cube[1][1][0] = temp[0];
		cube[1][1][1] = temp[1];
		cube[1][1][2] = temp[2];
		break;
	}
	case 9:
	{
		int order[5] = { 1, 4, 3, 5, 1 };
		int temp[3] = { 0, };
		for (int i = 0; i < 3; i++) {
			cube[order[i + 1]][2][0] = cube[order[i]][2][0];
			cube[order[i + 1]][2][1] = cube[order[i]][2][1];
			cube[order[i + 1]][2][2] = cube[order[i]][2][2];
			temp[0] = cube[order[i + 2]][2][0];
			temp[1] = cube[order[i + 2]][2][1];
			temp[2] = cube[order[i + 2]][2][2];
		}
		cube[1][2][0] = temp[0];
		cube[1][2][1] = temp[1];
		cube[1][2][2] = temp[2];
		//시계반대방향회전
		for (int k = 0; k < 2; k++) {
			int col = 0, row = 0, tmp, tmp2, i = 2;
			for (row; row < 2; row++) {
				tmp = cube[i][row + 1][col];
				cube[i][row + 1][col] = tmp;
			}
			for (col; col < 2; col++) {
				tmp2 = cube[i][row][col + 1];
				cube[i][row][col + 1] = cube[i][row][col];
				tmp = tmp2;
			}
			for (row; row > 0; row--) {
				tmp2 = cube[i][row - 1][col];
				cube[i][row - 1][col] = tmp;
				tmp = tmp2;
			}
			for (col; col > 0; col--) {
				tmp2 = cube[i][row][col - 1];
				cube[i][row][col - 1] = tmp;
				tmp = tmp2;
			}
		}
		break;
	}
	case 10:
	{
		int order[5] = { 1, 5, 3, 4, 1 };
		int temp[3] = { 0, };
		for (int i = 0; i < 3; i++) {
			cube[order[i + 1]][0][0] = cube[order[i]][0][0];
			cube[order[i + 1]][0][1] = cube[order[i]][0][1];
			cube[order[i + 1]][0][2] = cube[order[i]][0][2];
			temp[0] = cube[order[i + 2]][0][0];
			temp[1] = cube[order[i + 2]][0][1];
			temp[2] = cube[order[i + 2]][0][2];
		}
		cube[1][0][0] = temp[0];
		cube[1][0][1] = temp[1];
		cube[1][0][2] = temp[2];
		//시계반대방향회전
		for (int k = 0; k < 2; k++) {
			int col = 0, row = 0, tmp, tmp2, i = 0;
			for (row; row < 2; row++) {
				tmp = cube[i][row + 1][col];
				cube[i][row + 1][col] = tmp;
			}
			for (col; col < 2; col++) {
				tmp2 = cube[i][row][col + 1];
				cube[i][row][col + 1] = cube[i][row][col];
				tmp = tmp2;
			}
			for (row; row > 0; row--) {
				tmp2 = cube[i][row - 1][col];
				cube[i][row - 1][col] = tmp;
				tmp = tmp2;
			}
			for (col; col > 0; col--) {
				tmp2 = cube[i][row][col - 1];
				cube[i][row][col - 1] = tmp;
				tmp = tmp2;
			}
		}
		break;
	}
	case 11:
	{
		int order[5] = { 1, 5, 3, 4, 1 };
		int temp[3] = { 0, };
		for (int i = 0; i < 3; i++) {
			cube[order[i + 1]][1][0] = cube[order[i]][1][0];
			cube[order[i + 1]][1][1] = cube[order[i]][1][1];
			cube[order[i + 1]][1][2] = cube[order[i]][1][2];
			temp[0] = cube[order[i + 2]][1][0];
			temp[1] = cube[order[i + 2]][1][1];
			temp[2] = cube[order[i + 2]][1][2];
		}
		cube[1][1][0] = temp[0];
		cube[1][1][1] = temp[1];
		cube[1][1][2] = temp[2];
		break;
	}
	case 12:
	{
		int order[5] = { 1, 5, 3, 4, 1 };
		int temp[3] = { 0, };
		for (int i = 0; i < 3; i++) {
			cube[order[i + 1]][2][0] = cube[order[i]][2][0];
			cube[order[i + 1]][2][1] = cube[order[i]][2][1];
			cube[order[i + 1]][2][2] = cube[order[i]][2][2];
			temp[0] = cube[order[i + 2]][2][0];
			temp[1] = cube[order[i + 2]][2][1];
			temp[2] = cube[order[i + 2]][2][2];
		}
		cube[1][2][0] = temp[0];
		cube[1][2][1] = temp[1];
		cube[1][2][2] = temp[2];
		//시계방향회전
		for (int k = 0; k < 2; k++) {
			int col = 0, row = 0, tmp, tmp2, i = 2;
			for (col; col < 2; col++) {
				tmp = cube[i][row][col + 1];
				cube[i][row][col + 1] = cube[i][row][col];
			}
			for (row; row < 2; row++) {
				tmp2 = cube[i][row + 1][col];
				cube[i][row + 1][col] = tmp;
				tmp = tmp2;
			}
			for (col; col > 0; col--) {
				tmp2 = cube[i][row][col - 1];
				cube[i][row][col - 1] = tmp;
				tmp = tmp2;
			}
			for (row; row > 0; row--) {
				tmp2 = cube[i][row - 1][col];
				cube[i][row - 1][col] = tmp;
				tmp = tmp2;
			}
		}
		break;
	}
	default:
		break;
	}
}


int main() {
	int test_case;
	int m,c,p;
	cin >> test_case;
	for (int t = 1; t <= test_case; t++) {
		int val = 1;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					cube[i][j][k] = val++;
				}
			}
		}
		cin >> m;
		//회전 수행
		for (int i = 0; i < m; i++) {
			cin >> c;
			rotate(c);
		}

		//결과 출력
		cin >> p;
		cout << "#" << t << " ";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[p - 1][i][j] << " ";
			}
		}
		cout << "\n";
	}


	
}