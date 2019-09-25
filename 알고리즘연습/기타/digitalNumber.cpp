//
//  digitalNumber.cpp
//  digitalNumber
//
//  Created by 이준의 on 23/09/2019.
//  Copyright © 2019 이준의. All rights reserved.
//

/*
 문제 : 서로 다른 크기의 0~9 로 이루어진 숫자문자열을 TOP, MIDDLE, BOTTOM으로 정렬하여 출력하기

 예제 입력 : 3 MIDDLE    <- 3 개 문자열과 가운데 정렬
            5 123       <- 5의 크기를 가진 "123" 숫자문자열
			3 47
			7 56890
 예제 출력 : 
			..... ..... ..... ... ... ####### #...... ####### ####### #######
			....# ##### ##### ... ... #...... #...... #.....# #.....# #.....#
			....# ....# ....# #.# ### #...... #...... #.....# #.....# #.....#
			....# ##### ##### ### ..# ####### ####### ####### ####### #.....#
			....# #.... ....# ..# ..# ......# #.....# #.....# ......# #.....#
			....# ##### ##### ... ... ......# #.....# #.....# ......# #.....#
			..... ..... ..... ... ... ####### ####### ####### ......# #######
*/

/*
 해결 : 1. 모든 입력을 받은 후 가로 세로를 계산하여 '.' 과 ' '으로 이루어진 격자 배열을 생성
       2. 오프셋 개념을 활용하여 공백으로 구분된 서브 격자마다 숫자를 그리는 함수에 현재 오프셋 위치(서브 격자의 컬럼값)를 넘겨줌
	   3. 함수에서는 0~9까지 각각 그리기 함수를 for으로 구현, TOP,MIDDLE,BOTTOM에 따라 시작 ROW 값을 계산.
*/

#include <iostream>
#include <vector>
using namespace std;

void one(int index, int size, int length, string align, vector<vector<char>>& map) {
	index = index + size - 1;
	if (length == size || align == "TOP") {
		for (int i = 0; i < size; i++) {
			map[i][index] = '#';
		}
	}
	else if (align == "MIDDLE") {
		int start = length / 2 - size / 2;
		for (int i = start; i < start + size; i++) {
			map[i][index] = '#';
		}
	}
	else if (align == "BOTTOM") {
		int start = length - 1;
		for (int i = start; i > start - size; i--) {
			map[i][index] = '#';
		}
	}
}

// 그리는 순서
// 예 ) 5 2 <- 5크기의 2
// #####     #####    #####
// .....     ....#    ....#
// #####  -> ##### -> #####
// .....     .....    #....
// #####     #####    #####

void two(int index, int size, int width, int length, string align, vector<vector<char>>& map) {
	int start = index + width - size;
	int gap = size / 2;
	if (length == size || align == "TOP") {
		for (int i = 0, j = 0; i < 3; i++, j = j + gap) {
			for (int k = start; k < start + size; k++) {
				map[j][k] = '#';
			}
		}
		for (int i = start + size - 1, j = 0; j < gap; j++) {
			map[j][i] = '#';
		}
		for (int i = start, j = gap; j < size; j++) {
			map[j][i] = '#';
		}
	}
	else if (align == "MIDDLE") {
		int mid = length / 2 - size / 2;
		for (int i = 0, j = mid; i < 3; i++, j = j + gap) {
			for (int k = start; k < start + size; k++) {
				map[j][k] = '#';
			}
		}
		for (int i = start + size - 1, j = mid; j < mid + gap; j++) {
			map[j][i] = '#';
		}
		for (int i = start, j = mid + gap; j < size; j++) {
			map[j][i] = '#';
		}
	}
	else if (align == "BOTTOM") {
		int end = length - 1;
		for (int i = 0, j = end; i < 3; i++, j = j - gap) {
			for (int k = start; k < start + size; k++) {
				map[j][k] = '#';
			}
		}
		for (int i = start + size - 1, j = end - gap; j > end - size; j--) {
			map[j][i] = '#';
		}
		for (int i = start, j = end; j > end + 1 - size + gap; j--) {
			map[j][i] = '#';
		}
	}
}

void three(int index, int size, int width, int length, string align, vector<vector<char>>& map) {
	int start = index + width - size;
	int gap = size / 2;

	if (length == size || align == "TOP") {
		for (int i = 0, j = 0; i < 3; i++, j = j + gap) {
			for (int k = start; k < start + size; k++) {
				map[j][k] = '#';
			}
		}
		for (int i = start + size - 1, j = 0; j < size; j++) {
			map[j][i] = '#';
		}
	}
	else if (align == "MIDDLE") {
		int mid = length / 2 - size / 2;
		for (int i = 0, j = mid; i < 3; i++, j = j + gap) {
			for (int k = start; k < start + size; k++) {
				map[j][k] = '#';
			}
		}
		for (int i = start + size - 1, j = mid; j < mid + size; j++) {
			map[j][i] = '#';
		}

	}
	else if (align == "BOTTOM") {
		int end = length - 1;
		for (int i = 0, j = end; i < 3; i++, j = j - gap) {
			for (int k = start; k < start + size; k++) {
				map[j][k] = '#';
			}
		}
		for (int i = start + size - 1, j = end; j > end + 1 - size; j--) {
			map[j][i] = '#';
		}
	}
}

void four(int index, int size, int width, int length, string align, vector<vector<char>>& map) {
	int start = index + width - size;
	int gap = size / 2;
	if (length == size || align == "TOP") {
		for (int i = start; i < start + size; i++) {
			map[gap][i] = '#';
		}
		for (int i = 0; i < gap; i++) {
			map[i][start] = '#';
		}
		for (int i = 0; i < size; i++) {
			map[i][start + size - 1] = '#';
		}
	}
	else if (align == "MIDDLE") {
		int mid = length / 2 - size / 2;
		for (int i = start; i < start + size; i++) {
			map[mid + gap][i] = '#';
		}
		for (int i = mid; i < mid + gap; i++) {
			map[i][start] = '#';
		}
		for (int i = mid; i < mid + size; i++) {
			map[i][start + size - 1] = '#';
		}

	}
	else if (align == "BOTTOM") {
		int end = length - 1;
		for (int i = start; i < start + size; i++) {
			map[end - gap][i] = '#';
		}
		for (int i = end - gap; i > end - size; i--) {
			map[i][start] = '#';
		}
		for (int i = end; i > end - size; i--) {
			map[i][start + size - 1] = '#';
		}
	}
}

void five(int index, int size, int width, int length, string align, vector<vector<char>>& map) {
	int start = index + width - size;
	int gap = size / 2;

	if (length == size || align == "TOP") {
		for (int i = 0, j = 0; i < 3; i++, j = j + gap) {
			for (int k = start; k < start + size; k++) {
				map[j][k] = '#';
			}
		}
		for (int i = start + size - 1, j = gap; j < size; j++) {
			map[j][i] = '#';
		}

		for (int i = start, j = 0; j < gap; j++) {
			map[j][i] = '#';
		}
	}
	else if (align == "MIDDLE") {
		int mid = length / 2 - size / 2;
		for (int i = 0, j = mid; i < 3; i++, j = j + gap) {
			for (int k = start; k < start + size; k++) {
				map[j][k] = '#';
			}
		}
		for (int i = start + size - 1, j = mid + gap; j < mid + size; j++) {
			map[j][i] = '#';
		}

		for (int i = start, j = mid; j < mid + gap; j++) {
			map[j][i] = '#';
		}

	}
	else if (align == "BOTTOM") {
		int end = length - 1;
		for (int i = 0, j = end; i < 3; i++, j = j - gap) {
			for (int k = start; k < start + size; k++) {
				map[j][k] = '#';
			}
		}
		for (int i = start + size - 1, j = end; j > end - gap; j--) {
			map[j][i] = '#';
		}

		for (int i = start, j = end - gap; j > end - size; j--) {
			map[j][i] = '#';
		}
	}
}

void six(int index, int size, int width, int length, string align, vector<vector<char>>& map) {
	int start = index + width - size;
	int gap = size / 2;

	if (length == size || align == "TOP") {
		for (int i = 0; i < size; i++) {
			map[i][start] = '#';
		}
		for (int j = 0, k = gap; j < 2; j++, k += gap) {
			for (int i = start; i < start + size; i++) {
				map[k][i] = '#';
			}
		}
		for (int i = gap; i < size; i++) {
			map[i][start + size - 1] = '#';
		}
	}
	else if (align == "MIDDLE") {
		int mid = length / 2 - size / 2;
		for (int i = mid; i < mid + size; i++) {
			map[i][start] = '#';
		}
		for (int j = 0, k = mid + gap; j < 2; j++, k += gap) {
			for (int i = start; i < start + size; i++) {
				map[k][i] = '#';
			}
		}
		for (int i = mid + gap; i < mid + size; i++) {
			map[i][start + size - 1] = '#';
		}
	}
	else if (align == "BOTTOM") {
		int end = length - 1;
		for (int i = end; i > end - size; i--) {
			map[i][start] = '#';
		}
		for (int j = 0, k = end - gap; j < 2; j++, k += gap) {
			for (int i = start; i < start + size; i++) {
				map[k][i] = '#';
			}
		}
		for (int i = end; i > end - gap; i--) {
			map[i][start + size - 1] = '#';
		}
	}
}

void seven(int index, int size, int width, int length, string align, vector<vector<char>>& map) {
	int start = index + width - size;

	if (length == size || align == "TOP") {
		for (int i = start; i < start + size; i++) {
			map[0][i] = '#';
		}
		for (int i = 0; i < size; i++) {
			map[i][start + size - 1] = '#';
		}
	}
	else if (align == "MIDDLE") {
		int mid = length / 2 - size / 2;
		for (int i = start; i < start + size; i++) {
			map[mid][i] = '#';
		}
		for (int i = mid; i < mid + size; i++) {
			map[i][start + size - 1] = '#';
		}
	}
	else if (align == "BOTTOM") {
		int end = length - 1;
		for (int i = start; i < start + size; i++) {
			map[end - size + 1][i] = '#';
		}
		for (int i = end; i > end - size; i--) {
			map[i][start + size - 1] = '#';
		}
	}
}

void eight(int index, int size, int width, int length, string align, vector<vector<char>>& map) {
	int start = index + width - size;
	int gap = size / 2;

	if (length == size || align == "TOP") {
		for (int i = 0, j = 0; i < 3; i++, j = j + gap) {
			for (int k = start; k < start + size; k++) {
				map[j][k] = '#';
			}
		}
		for (int i = start + size - 1, j = 0; j < size; j++) {
			map[j][i] = '#';
		}

		for (int i = start, j = 0; j < size; j++) {
			map[j][i] = '#';
		}
	}
	else if (align == "MIDDLE") {
		int mid = length / 2 - size / 2;
		for (int i = 0, j = mid; i < 3; i++, j = j + gap) {
			for (int k = start; k < start + size; k++) {
				map[j][k] = '#';
			}
		}
		for (int i = start + size - 1, j = mid; j < mid + size; j++) {
			map[j][i] = '#';
		}

		for (int i = start, j = mid; j < mid + size; j++) {
			map[j][i] = '#';
		}
	}
	else if (align == "BOTTOM") {
		int end = length - 1;
		for (int i = 0, j = end; i < 3; i++, j = j - gap) {
			for (int k = start; k < start + size; k++) {
				map[j][k] = '#';
			}
		}
		for (int i = start + size - 1, j = end; j > end - size; j--) {
			map[j][i] = '#';
		}

		for (int i = start, j = end; j > end - size; j--) {
			map[j][i] = '#';
		}
	}
}


void nine(int index, int size, int width, int length, string align, vector<vector<char>>& map) {
	int start = index + width - size;
	int gap = size / 2;

	if (length == size || align == "TOP") {
		for (int j = 0, k = 0; j < 2; j++, k += gap) {
			for (int i = start; i < start + size; i++) {
				map[k][i] = '#';
			}
		}
		for (int i = 0; i < gap; i++) {
			map[i][start] = '#';
		}
		for (int i = 0; i < size; i++) {
			map[i][start + size - 1] = '#';
		}
	}
	else if (align == "MIDDLE") {
		int mid = length / 2 - size / 2;
		for (int j = 0, k = mid; j < 2; j++, k += gap) {
			for (int i = start; i < start + size; i++) {
				map[k][i] = '#';
			}
		}
		for (int i = mid; i < mid + gap; i++) {
			map[i][start] = '#';
		}
		for (int i = mid; i < mid + size; i++) {
			map[i][start + size - 1] = '#';
		}
	}
	else if (align == "BOTTOM") {
		int end = length - 1;
		for (int j = 0, k = end - gap; j < 2; j++, k -= gap) {
			for (int i = start; i < start + size; i++) {
				map[k][i] = '#';
			}
		}
		for (int i = end - gap; i > end - size; i--) {
			map[i][start] = '#';
		}
		for (int i = end; i > end - size; i--) {
			map[i][start + size - 1] = '#';
		}
	}
}


void zero(int index, int size, int width, int length, string align, vector<vector<char>>& map) {
	int start = index + width - size;
	int gap = size / 2;

	if (length == size || align == "TOP") {
		for (int k = 0, j = 0; k < 2; k++, j += size - 1) {
			for (int i = start; i < start + size; i++) {
				map[j][i] = '#';
			}
		}
		for (int k = 0, j = start; k < 2; k++, j += size - 1) {
			for (int i = 0; i < size; i++) {
				map[i][j] = '#';
			}
		}

	}
	else if (align == "MIDDLE") {
		int mid = length / 2 - size / 2;
		for (int k = 0, j = mid; k < 2; k++, j += size - 1) {
			for (int i = start; i < start + size; i++) {
				map[j][i] = '#';
			}
		}
		for (int k = 0, j = start; k < 2; k++, j += size - 1) {
			for (int i = mid; i < size; i++) {
				map[i][j] = '#';
			}
		}
	}
	else if (align == "BOTTOM") {
		int end = length - 1;
		for (int k = 0, j = end; k < 2; k++, j -= size - 1) {
			for (int i = start; i < start + size; i++) {
				map[j][i] = '#';
			}
		}
		for (int k = 0, j = start; k < 2; k++, j += size - 1) {
			for (int i = end; i > end - size; i--) {
				map[i][j] = '#';
			}
		}
	}
}


int main(int argc, const char* argv[]) {

	int n;
	string s;
	cin >> n >> s;

	vector<pair<int, char>> info;
	int width = 0;
	int length = 0;

	// 데이터 입력
	for (int i = 0; i < n; ++i) {
		int size;
		string input;
		cin >> size >> input;
		cin.ignore();
		width += size * input.size();
		if (size > length) {
			length = size;
		}
		for (int j = 0; j < input.size(); j++) {
			info.push_back(make_pair(size, input[j]));
		}
	}

	vector<vector<char>> map;

	int total_width = width + info.size() - 1;

	// ' ' 과 '.' 이루어진 격자배열 생성
	for (int i = 0; i < length; i++) {
		vector<char> element(total_width, ' ');
		map.push_back(element);
	}
	int width_index = 0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < info.size(); j++) {
			for (int k = 0; k < info[j].first; k++) {
				map[i][width_index] = '.';
				width_index++;
			}
			width_index++;
		}
		width_index = 0;
	}

	// 다음 offset은 offset += 숫자 개별크기 + 공백;
	// 예 ) 5 123 의 경우 
	// 1의 오프셋 : 0
	// 2의 오프셋 : 0 + 5 + 1 = 6
	// 3의 오프셋 : 6 + 5 + 1 = 12
	int offset = 0;
	for (int i = 0; i < info.size(); i++) {
		if (info[i].second == '1') {
			one(offset, info[i].first, length, s, map);
		}
		else if (info[i].second == '2') {
			two(offset, info[i].first, info[i].first, length, s, map);
		}
		else if (info[i].second == '3') {
			three(offset, info[i].first, info[i].first, length, s, map);
		}
		else if (info[i].second == '4') {
			four(offset, info[i].first, info[i].first, length, s, map);
		}
		else if (info[i].second == '5') {
			five(offset, info[i].first, info[i].first, length, s, map);
		}
		else if (info[i].second == '6') {
			six(offset, info[i].first, info[i].first, length, s, map);
		}
		else if (info[i].second == '7') {
			seven(offset, info[i].first, info[i].first, length, s, map);
		}
		else if (info[i].second == '8') {
			eight(offset, info[i].first, info[i].first, length, s, map);
		}
		else if (info[i].second == '9') {
			nine(offset, info[i].first, info[i].first, length, s, map);
		}
		else if (info[i].second == '0') {
			zero(offset, info[i].first, info[i].first, length, s, map);
		}
		offset += info[i].first + 1;
	}

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < total_width; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}
