/*
 PlusOne
 [1,2,3] �Է� �� [1,2,4] ���
 [9,9,9] �Է� �� [1,0,0,0] ���
 9ó���� 0 �� �ܴ� +1 ó���԰� ���ÿ� break; ���� ����Ѱ� ����Ʈ
 for�� �Ŀ� ���� �� ���Ұ� 0�϶� �迭�� resize �Ͽ� 1�� �߰�
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