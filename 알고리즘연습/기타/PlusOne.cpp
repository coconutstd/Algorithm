/*
 PlusOne
 [1,2,3] 입력 시 [1,2,4] 출력
 [9,9,9] 입력 시 [1,0,0,0] 출력
 9처리는 0 그 외는 +1 처리함과 동시에 break; 문을 사용한게 포인트
 for문 후에 제일 앞 원소가 0일때 배열을 resize 하여 1을 추가
*/

#include <vector>
#include <iostream>

using namespace std;

vector<int> plusOne(vector<int> digits) {
	for (int i = digits.size() - 1; i >= 0; i--) {
		if (digits[i] != 9) {
			digits[i]++;
			break;
		}
		else {
			digits[i] = 0;
		}
	}
	vector<int> result;
	if (digits[0] == 0) {
		result.resize(digits.size() + 1);
		result[0] = 1;
		return result;
	}

	return digits;
}

int main() {
	vector<int> digits = { 9,9,9 };
	vector<int> result = plusOne(digits);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}