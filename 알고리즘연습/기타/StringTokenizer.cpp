/*
 String Tokenizer
 ���ڿ� ���ڸ� ����, �� ���ڰ� �ƴ� ���ڸ� �и��� ���� �迭�� �ֽ��ϴ�.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

	vector<int> tokenizer;
	string str = "123,-45 784-";
	string num = "";
	for (int i = 0; i < str.size(); i++) {
		if (isalnum(str[i])) {
			num += str[i];
			if (i == str.size() - 1) {
				tokenizer.push_back(stoi(num));
			}
		}
		else {
			if (num != "") {
				tokenizer.push_back(stoi(num));
				num = "";
			}
		}
	}

	for (int i = 0; i < tokenizer.size(); i++) {
		cout << tokenizer[i] << endl;
	}

}