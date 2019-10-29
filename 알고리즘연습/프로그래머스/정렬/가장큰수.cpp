/*
 ���� ū ��
 [3,30,34] �� �迭�� ���� �� ���� ū �� �� 34330 �� ã�� ��
 ���ڿ� �� �Լ��� �ۼ��Ͽ� �ذ�
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(const string& a, const string& b) {
	return a + b > b + a ? true : false;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> charArr;
	for (int i : numbers) {
		charArr.push_back(to_string(i));
	}
	sort(charArr.begin(), charArr.end(), cmp);
	for (string s : charArr) {
		answer += s;
	}
	if (answer[0] == '0') return "0";
	return answer;
}