/*
 JewelsAndStones
 보석을 set에 저장한후, 돌들을 하나씩 set에 있는 키인지 확인하여 보석의 개수를 구함
 자바와 달리 C++을 contains함수가 없으므로 find의 리턴값이 end인지를 확인함으로써 구현
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