#include <iostream>
#include <vector>
using namespace std;


int main() {

	vector<int> integer;
	for (int i; cin >> i;) integer.push_back(i);
	if (cin.eof()) {
		printf("파일이 끝난 상태입니다\n");
	}
	if (cin.bad()) {
		printf("파일이 나쁜 상태입니다\n");
	}
	if (cin.fail()) {
		printf("fail 상태입니다\n");
	}

	for (int i = 0; i < integer.size(); i++) {
		cout << integer[i];
	}

	return 0;
}