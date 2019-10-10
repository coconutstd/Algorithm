/*
 JewelsAndStones
 ������ set�� ��������, ������ �ϳ��� set�� �ִ� Ű���� Ȯ���Ͽ� ������ ������ ����
 �ڹٿ� �޸� C++�� contains�Լ��� �����Ƿ� find�� ���ϰ��� end������ Ȯ�������ν� ����
*/

#include <string>
#include <iostream>
#include <set>

using namespace std;

int solve(string J, string S) {
	set<char> s;
	for (char jewel : J) {
		s.insert(jewel);
	}
	int count = 0;
	for (char stone : S) {
		if (s.find(stone) != s.end()) {
			count++;
		}
	}
	return count;

}

int main() {
	string J = "aA";
	string S = "aAAbbb";
	cout << solve(J, S);
}