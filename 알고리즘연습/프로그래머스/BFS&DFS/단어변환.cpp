/*
 ���α׷��ӽ� ����� Kit
 �ܾȯ
 BFS�� ť ������ ��ŭ �ݺ��� ���� �ذ�
 neightbors �Լ��� Set�� Ȱ���� �̿��� �ܾ �ִٸ� Set���� �����س����� ����� ����Ʈ
*/
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<string> neighbors(string word, set<string>& dict) {
	vector<string> result;
	for (int i = 0; i < word.size(); i++) {
		string copy = word;
		for (char ch = 'a'; ch <= 'z'; ch++) {
			copy[i] = ch;
			if (dict.find(copy) != dict.end()) {
				dict.erase(copy);
				result.push_back(copy);
			}
		}
	}
	return result;
}

int solution(string begin, string target, vector<string> words) {
	if (words.size() == 0) return 0;
	int answer = 0;
	set<string> dict;
	queue<string> q;
	for (int i = 0; i < words.size(); i++) {
		dict.insert(words[i]);
	}

	if (dict.find(target) == dict.end()) return 0;

	q.push(begin);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			string word = q.front();
			q.pop();
			if (word == target) return answer;
			for (string next : neighbors(word, dict)) {
				q.push(next);
			}
		}
		answer++;
	}
	return answer;
}