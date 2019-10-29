/*
 가장 큰 수
 [3,30,34] 의 배열이 있을 때 가장 큰 수 인 34330 을 찾는 것
 문자열 비교 함수를 작성하여 해결
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