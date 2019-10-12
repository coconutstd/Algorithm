/*
 프로그래머스 고득점 Kit
 단어변환
 BFS의 큐 사이즈 만큼 반복을 통한 해결
 neightbors 함수와 Set을 활용해 이웃한 단어가 있다면 Set에서 제거해나가는 방식이 포인트
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