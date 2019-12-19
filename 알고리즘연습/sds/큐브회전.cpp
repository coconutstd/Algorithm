#include <iostream>
#include <vector>
using namespace std;

int cube[6][3][3] = {
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	},
	{
		{10,11,12},
		{13,14,15},
		{16,17,18}
	},
	{
		{19,20,21},
		{22,23,24},
		{25,26,27}
	},
	{
		{34,35,36},
		{31,32,33},
		{28,29,30}
	},
	{
		{37,38,39},
		{40,41,42},
		{43,44,45}
	},
	{
		{46,47,48},
		{49,50,51},
		{52,53,54}
	}
};


void rotate(int c) {
	switch (c)
	{
	case 1: 
	{
		int order[5] = { 0,3,2,1,0 };
		int temp[3] = { 0, };
		int temp2[3] = { cube[order[0]][0][0],cube[order[0]][1][0],cube[order[0]][2][0] };
		for (int i = 0; i < 4; i++) {
			temp[0] = cube[order[i + 1]][0][0];
			temp[1] = cube[order[i + 1]][1][0];
			temp[2] = cube[order[i + 1]][2][0];
			cube[order[i + 1]][0][0] = temp2[0];
			cube[order[i + 1]][1][0] = temp2[1];
			cube[order[i + 1]][2][0] = temp2[2];
			temp2[0] = temp[0];
			temp2[1] = temp[1];
			temp2[2] = temp[2];
		}

		//시계반대방향회전
		for (int k = 0; k < 2; k++) {
			int col = 0, row = 0, tmp,i=4;
			int tmp2 = cube[i][row][col];
			for (row; row < 2; row++) {
				tmp = cube[i][row + 1][col];
				cube[i][row + 1][col] = tmp2;
				tmp2 = tmp;
			}
			for (col; col < 2; col++) {
				tmp = cube[i][row][col + 1];
				cube[i][row][col + 1] = tmp2;
				tmp2 = tmp;
			}
			for (row; row > 0; row--) {
				tmp = cube[i][row - 1][col];
				cube[i][row - 1][col] = tmp2;
				tmp2 = tmp;
			}
			for (col; col > 0; col--) {
				tmp = cube[i][row][col - 1];
				cube[i][row][col - 1] = tmp2;
				tmp2 = tmp;
			}
		}
		break;
	}
	case 2:
	{
		int order[5] = { 0, 3, 2, 1, 0 };
		int temp[3] = { 0, };
		int temp2[3] = { cube[order[0]][0][1], cube[order[0]][1][1], cube[order[0]][2][1] };
		for (int i = 0; i < 4; i++) {
			temp[0] = cube[order[i + 1]][0][1];
			temp[1] = cube[order[i + 1]][1][1];
			temp[2] = cube[order[i + 1]][2][1];
			cube[order[i + 1]][0][1] = temp2[0];
			cube[order[i + 1]][1][1] = temp2[1];
			cube[order[i + 1]][2][1] = temp2[2];
			temp2[0] = temp[0];
			temp2[1] = temp[1];
			temp2[2] = temp[2];
		}
		break;
	}
	case 3:
	{
		int order[5] = { 0, 3, 2, 1, 0 };
		int temp[3] = { 0, };
		int temp2[3] = { cube[order[0]][0][2],cube[order[0]][1][2], cube[order[0]][2][2] };
		for (int i = 0; i < 4; i++) {
			temp[0] = cube[order[i + 1]][0][2];
			temp[1] = cube[order[i + 1]][1][2];
			temp[2] = cube[order[i + 1]][2][2];
			cube[order[i + 1]][0][2] = temp2[0];
			cube[order[i + 1]][1][2] = temp2[1];
			cube[order[i + 1]][2][2] = temp2[2];
			temp2[0] = temp[0];
			temp2[1] = temp[1];
			temp2[2] = temp[2];
		}
		//시계방향회전
		for (int k = 0; k < 2; k++) {
			int col = 0, row = 0, tmp, i = 5;
			int tmp2 = cube[i][row][col];
			for (col; col < 2; col++) {
				tmp = cube[i][row][col + 1];
				cube[i][row][col + 1] = tmp2;
				tmp2 = tmp;
			}
			for (row; row < 2; row++) {
				tmp = cube[i][row + 1][col];
				cube[i][row + 1][col] = tmp2;
				tmp2 = tmp;
			}
			for (col; col > 0; col--) {
				tmp = cube[i][row][col - 1];
				cube[i][row][col - 1] = tmp2;
				tmp2 = tmp;
			}
			for (row; row > 0; row--) {
				tmp = cube[i][row - 1][col];
				cube[i][row - 1][col] = tmp2;
				tmp2 = tmp;
			}
		}
		break;
	}
	case 4:
	{
		int order[5] = { 0, 1, 2, 3, 0 };
		int temp[3] = { 0, };
		int temp2[3] = { cube[order[0]][0][0],cube[order[0]][1][0], cube[order[0]][2][0] };
		for (int i = 0; i < 4; i++) {
			temp[0] = cube[order[i + 1]][0][0];
			temp[1] = cube[order[i + 1]][1][0];
			temp[2] = cube[order[i + 1]][2][0];
			cube[order[i + 1]][0][0] = temp2[0];
			cube[order[i + 1]][1][0] = temp2[1];
			cube[order[i + 1]][2][0] = temp2[2];
			temp2[0] = temp[0];
			temp2[1] = temp[1];
			temp2[2] = temp[2];
		}

		//시계방향회전
		for (int k = 0; k < 2; k++) {
			int col = 0, row = 0, tmp, i = 4;
			int tmp2 = cube[i][row][col];
			for (col; col < 2; col++) {
				tmp = cube[i][row][col + 1];
				cube[i][row][col + 1] = tmp2;
				tmp2 = tmp;
			}
			for (row; row < 2; row++) {
				tmp = cube[i][row + 1][col];
				cube[i][row + 1][col] = tmp2;
				tmp2 = tmp;
			}
			for (col; col > 0; col--) {
				tmp = cube[i][row][col - 1];
				cube[i][row][col - 1] = tmp2;
				tmp2 = tmp;
			}
			for (row; row > 0; row--) {
				tmp = cube[i][row - 1][col];
				cube[i][row - 1][col] = tmp2;
				tmp2 = tmp;
			}
		}
		break;
	}
	case 5:
	{
		int order[5] = { 0, 1, 2, 3, 0 };
		int temp[3] = { 0, };
		int temp2[3] = { cube[order[0]][0][1],cube[order[0]][1][1], cube[order[0]][2][1] };
		for (int i = 0; i < 4; i++) {
			temp[0] = cube[order[i + 1]][0][1];
			temp[1] = cube[order[i + 1]][1][1];
			temp[2] = cube[order[i + 1]][2][1];
			cube[order[i + 1]][0][0] = temp2[0];
			cube[order[i + 1]][1][1] = temp2[1];
			cube[order[i + 1]][2][1] = temp2[2];
			temp2[0] = temp[0];
			temp2[1] = temp[1];
			temp2[2] = temp[2];
		}
		break;
	}
	case 6:
	{
		int order[5] = { 0, 1, 2, 3, 0 };
		int temp[3] = { 0, };
		int temp2[3] = { cube[order[0]][0][2],cube[order[0]][1][2], cube[order[0]][2][2] };
		for (int i = 0; i < 4; i++) {
			temp[0] = cube[order[i + 1]][0][2];
			temp[1] = cube[order[i + 1]][1][2];
			temp[2] = cube[order[i + 1]][2][2];
			cube[order[i + 1]][0][2] = temp2[0];
			cube[order[i + 1]][1][2] = temp2[1];
			cube[order[i + 1]][2][2] = temp2[2];
			temp2[0] = temp[0];
			temp2[1] = temp[1];
			temp2[2] = temp[2];
		}

		//시계반대방향회전
		for (int k = 0; k < 2; k++) {
			int col = 0, row = 0, tmp, i = 5;
			int tmp2 = cube[i][row][col];
			for (row; row < 2; row++) {
				tmp = cube[i][row + 1][col];
				cube[i][row + 1][col] = tmp2;
				tmp2 = tmp;
			}
			for (col; col < 2; col++) {
				tmp = cube[i][row][col + 1];
				cube[i][row][col + 1] = tmp2;
				tmp2 = tmp;
			}
			for (row; row > 0; row--) {
				tmp = cube[i][row - 1][col];
				cube[i][row - 1][col] = tmp2;
				tmp2 = tmp;
			}
			for (col; col > 0; col--) {
				tmp = cube[i][row][col - 1];
				cube[i][row][col - 1] = tmp2;
				tmp2 = tmp;
			}
		}
		break;
	}
	case 7:
	{
		int order[5] = { 1, 4, 3, 5, 1 };
		int temp[3] = { 0, };
		int temp2[3] = { cube[order[0]][0][0],cube[order[0]][0][1], cube[order[0]][0][2] };
		for (int i = 0; i < 4; i++) {
			temp[0] = cube[order[i + 1]][0][0];
			temp[1] = cube[order[i + 1]][0][1];
			temp[2] = cube[order[i + 1]][0][2];
			cube[order[i + 1]][0][0] = temp2[0];
			cube[order[i + 1]][0][1] = temp2[1];
			cube[order[i + 1]][0][2] = temp2[2];
			temp2[0] = temp[0];
			temp2[1] = temp[1];
			temp2[2] = temp[2];
		}
		//시계방향회전
		for (int k = 0; k < 2; k++) {
			int col = 0, row = 0, tmp, i = 0;
			int tmp2 = cube[i][row][col];
			for (col; col < 2; col++) {
				tmp = cube[i][row][col + 1];
				cube[i][row][col + 1] = tmp2;
				tmp2 = tmp;
			}
			for (row; row < 2; row++) {
				tmp = cube[i][row + 1][col];
				cube[i][row + 1][col] = tmp2;
				tmp2 = tmp;
			}
			for (col; col > 0; col--) {
				tmp = cube[i][row][col - 1];
				cube[i][row][col - 1] = tmp2;
				tmp2 = tmp;
			}
			for (row; row > 0; row--) {
				tmp = cube[i][row - 1][col];
				cube[i][row - 1][col] = tmp2;
				tmp2 = tmp;
			}
		}
		break;
	}
	case 8:
	{
		int order[5] = { 1, 4, 3, 5, 1 };
		int temp[3] = { 0, };
		int temp2[3] = { cube[order[0]][1][0],cube[order[0]][1][1], cube[order[0]][1][2] };
		for (int i = 0; i < 4; i++) {
			temp[0] = cube[order[i + 1]][1][0];
			temp[1] = cube[order[i + 1]][1][1];
			temp[2] = cube[order[i + 1]][1][2];
			cube[order[i + 1]][1][0] = temp2[0];
			cube[order[i + 1]][1][1] = temp2[1];
			cube[order[i + 1]][1][2] = temp2[2];
			temp2[0] = temp[0];
			temp2[1] = temp[1];
			temp2[2] = temp[2];
		}
		break;
	}
	case 9:
	{
		int order[5] = { 1, 4, 3, 5, 1 };
		int temp[3] = { 0, };
		int temp2[3] = { cube[order[0]][2][0],cube[order[0]][2][1], cube[order[0]][2][2] };
		for (int i = 0; i < 4; i++) {
			temp[0] = cube[order[i + 1]][2][0];
			temp[1] = cube[order[i + 1]][2][1];
			temp[2] = cube[order[i + 1]][2][2];
			cube[order[i + 1]][2][0] = temp2[0];
			cube[order[i + 1]][2][1] = temp2[1];
			cube[order[i + 1]][2][2] = temp2[2];
			temp2[0] = temp[0];
			temp2[1] = temp[1];
			temp2[2] = temp[2];
		}
		//시계반대방향회전
		for (int k = 0; k < 2; k++) {
			int col = 0, row = 0, tmp, i = 2;
			int tmp2 = cube[i][row][col];
			for (row; row < 2; row++) {
				tmp = cube[i][row + 1][col];
				cube[i][row + 1][col] = tmp2;
				tmp2 = tmp;
			}
			for (col; col < 2; col++) {
				tmp = cube[i][row][col + 1];
				cube[i][row][col + 1] = tmp2;
				tmp2 = tmp;
			}
			for (row; row > 0; row--) {
				tmp = cube[i][row - 1][col];
				cube[i][row - 1][col] = tmp2;
				tmp2 = tmp;
			}
			for (col; col > 0; col--) {
				tmp = cube[i][row][col - 1];
				cube[i][row][col - 1] = tmp2;
				tmp2 = tmp;
			}
		}
		break;
	}
	case 10:
	{
		int order[5] = { 1, 5, 3, 4, 1 };
		int temp[3] = { 0, };
		int temp2[3] = { cube[order[0]][0][0],cube[order[0]][0][1], cube[order[0]][0][2] };
		for (int i = 0; i < 4; i++) {
			temp[0] = cube[order[i + 1]][0][0];
			temp[1] = cube[order[i + 1]][0][1];
			temp[2] = cube[order[i + 1]][0][2];
			cube[order[i + 1]][0][0] = temp2[0];
			cube[order[i + 1]][0][1] = temp2[1];
			cube[order[i + 1]][0][2] = temp2[2];
			temp2[0] = temp[0];
			temp2[1] = temp[1];
			temp2[2] = temp[2];
		}
		//시계반대방향회전
		for (int k = 0; k < 2; k++) {
			int col = 0, row = 0, tmp, i = 0;
			int tmp2 = cube[i][row][col];
			for (row; row < 2; row++) {
				tmp = cube[i][row + 1][col];
				cube[i][row + 1][col] = tmp2;
				tmp2 = tmp;
			}
			for (col; col < 2; col++) {
				tmp = cube[i][row][col + 1];
				cube[i][row][col + 1] = tmp2;
				tmp2 = tmp;
			}
			for (row; row > 0; row--) {
				tmp = cube[i][row - 1][col];
				cube[i][row - 1][col] = tmp2;
				tmp2 = tmp;
			}
			for (col; col > 0; col--) {
				tmp = cube[i][row][col - 1];
				cube[i][row][col - 1] = tmp2;
				tmp2 = tmp;
			}
		}
		break;
	}
	case 11:
	{
		int order[5] = { 1, 5, 3, 4, 1 };
		int temp[3] = { 0, };
		int temp2[3] = { cube[order[0]][1][0],cube[order[0]][1][1], cube[order[0]][1][2] };
		for (int i = 0; i < 4; i++) {
			temp[0] = cube[order[i + 1]][1][0];
			temp[1] = cube[order[i + 1]][1][1];
			temp[2] = cube[order[i + 1]][1][2];
			cube[order[i + 1]][1][0] = temp2[0];
			cube[order[i + 1]][1][1] = temp2[1];
			cube[order[i + 1]][1][2] = temp2[2];
			temp2[0] = temp[0];
			temp2[1] = temp[1];
			temp2[2] = temp[2];
		}
		break;
	}
	case 12:
	{
		int order[5] = { 1, 5, 3, 4, 1 };
		int temp[3] = { 0, };
		int temp2[3] = { cube[order[0]][2][0],cube[order[0]][2][1], cube[order[0]][2][2] };
		for (int i = 0; i < 4; i++) {
			temp[0] = cube[order[i + 1]][2][0];
			temp[1] = cube[order[i + 1]][2][1];
			temp[2] = cube[order[i + 1]][2][2];
			cube[order[i + 1]][2][0] = temp2[0];
			cube[order[i + 1]][2][1] = temp2[1];
			cube[order[i + 1]][2][2] = temp2[2];
			temp2[0] = temp[0];
			temp2[1] = temp[1];
			temp2[2] = temp[2];
		}
		//시계방향회전
		for (int k = 0; k < 2; k++) {
			int col = 0, row = 0, tmp, i = 2;
			int tmp2 = cube[i][row][col];
			for (col; col < 2; col++) {
				tmp = cube[i][row][col + 1];
				cube[i][row][col + 1] = tmp2;
				tmp2 = tmp;
			}
			for (row; row < 2; row++) {
				tmp = cube[i][row + 1][col];
				cube[i][row + 1][col] = tmp2;
				tmp2 = tmp;
			}
			for (col; col > 0; col--) {
				tmp = cube[i][row][col - 1];
				cube[i][row][col - 1] = tmp2;
				tmp2 = tmp;
			}
			for (row; row > 0; row--) {
				tmp = cube[i][row - 1][col];
				cube[i][row - 1][col] = tmp2;
				tmp2 = tmp;
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
		//for (int i = 0; i < 6; i++) {
		//	for (int j = 0; j < 3; j++) {
		//		for (int k = 0; k < 3; k++) {
		//			cube[i][j][k] = val++;
		//		}
		//	}
		//}
		cin >> m;
		//회전 수행
		for (int i = 0; i < m; i++) {
			cin >> c;
			rotate(c);

			cin >> p;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cout << cube[p - 1][i][j] << " ";
				}
			}
		}

		////결과 출력
		//cin >> p;
		//cout << "#" << t << " ";
		//for (int i = 0; i < 3; i++) {
		//	for (int j = 0; j < 3; j++) {
		//		cout << cube[p - 1][i][j] << " ";
		//	}
		//}
		//cout << "\n";
	}


	
}