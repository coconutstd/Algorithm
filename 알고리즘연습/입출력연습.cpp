#include <iostream>
#include <vector>
using namespace std;


int main() {

	vector<int> integer;
	for (int i; cin >> i;) integer.push_back(i);
	if (cin.eof()) {
		printf("������ ���� �����Դϴ�\n");
	}
	if (cin.bad()) {
		printf("������ ���� �����Դϴ�\n");
	}
	if (cin.fail()) {
		printf("fail �����Դϴ�\n");
	}

	for (int i = 0; i < integer.size(); i++) {
		cout << integer[i];
	}

	return 0;
}