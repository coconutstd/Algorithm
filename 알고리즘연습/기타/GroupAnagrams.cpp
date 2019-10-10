/*
 GroupAnagrams
 
 "eat", "tea", "tan", "ate", "nat", "bat" �� �Է��� �޾� ���� Anagram�� �׷� ���� ���� ���
 �� ���ڿ��� �����Ͽ� key������ ����°� ����Ʈ, �� �� Map�� �̿��Ͽ� Ű���� ��ġ�ϴ� �Ƴ��׷����� push_back
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