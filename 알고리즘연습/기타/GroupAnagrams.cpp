/*
 GroupAnagrams
 
 "eat", "tea", "tan", "ate", "nat", "bat" 의 입력을 받아 서로 Anagram인 그룹 끼리 묶어 출력
 각 문자열을 정렬하여 key값으로 만드는게 포인트, 그 후 Map을 이용하여 키값이 일치하는 아나그램들을 push_back
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

void groupAnagrams(vector<string> list) {
	map<string, vector<string>> m;
	for (string str : list) {
		vector<char> charArray;
		for (char ch : str) {
			charArray.push_back(ch);
		}
		sort(charArray.begin(), charArray.end());
		string key;
		for (char ch : charArray) {
			key += ch;
		}
		m[key].push_back(str);
	}
	for (map<string, vector<string>>::iterator i = m.begin(); i != m.end(); i++) {
		for (int j = 0; j < i->second.size(); j++) {
			cout << i->second[j] <<" ";
		}
		cout << endl;
	}
}

int main() {
	vector<string> list = { "eat", "tea", "tan", "ate", "nat", "bat" };
	groupAnagrams(list);
}