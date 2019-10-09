/*
 UniqueEmailAddresses
 email�ּ��� @ ���� '.' �����ϰ� '+' ���� ���� ��� �����ϰ� @ ���� ������ ���ڿ��� �����Ͽ� ó��
 set�� �����Ͽ� �̸��� �ּҵ��� ������
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

string makeUsername(string email) {
	string result = "";
	for (char ch : email) {
		if (ch == '.') {
			continue;
		}
		if (ch == '+') {
			break;
		}
		if (ch == '@') {
			break;
		}
		result += ch;
	}
	return result;
}

string makeDomainname(string email) {
	return email.substr(email.find('@')+1);
}

int numUniqueEmails(vector<string> emails) {
	set<string> set;

	for (string email : emails) {
		string username = makeUsername(email);
		string domainname = makeDomainname(email);

		string newemail = username + '@' + domainname;
		cout << newemail << endl;
		set.insert(newemail);
	}

	return set.size();
	
}

int main() {
	vector<string> emails = {
		"test.email+james@coding.com",
		"test.e.mail+toto.jane@coding.com",
		"testemail+tom@cod.ing.com"
	};
	cout << numUniqueEmails(emails) << endl;
}