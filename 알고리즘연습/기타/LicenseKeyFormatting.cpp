/*
 LicenseKeyFormatting
 ��Ʈ�� �Է°� k�Է��� �־����� ���ڿ��� �뽬�� ��� �����ϰ�, �빮�ڷ� ���� �� �ڿ��� ���� k ��° ���� �뽬 �߰�
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string str = "8F3Z-2e-9-wabcdef";
	int k = 2;
	cout << str << endl;
	int index = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '-') {
			str[index] = str[i];
			index++;
		}
	}
	str.resize(index);

	int leng = str.size();
	for (int i = 0; i < leng; i++) {
		str[i] = toupper(str[i]);
	}
	for (int i = k; i < leng; i += k) {
		str.insert(leng - i, "-");
	}
	cout << "====Formating=====\n";
	cout << str;
}