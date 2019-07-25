#include <iostream>
#include <string>
#include <list>

using namespace std;

class Editor
{
	list<char> &s;
	list<char>::iterator lt;
public:
	Editor(list<char>& _s):s(_s){
		lt = s.end();
	};
	void input(string);
	void L() { if (lt == s.begin()) return;  lt--; }
	void D() { if (lt == s.end()) return;  lt++; }
	void B() { if (lt == s.begin()) return; lt--;  lt = s.erase(lt); }
	void P(char x) { lt = s.insert(lt, x); lt++; }
	string print();
};

void Editor::input(string o) {
	if (o[0] == 'L') {
		L();
	}
	else if (o[0] == 'D') {
		D();
	}
	else if (o[0] == 'B') {
		B();
	}
	else if (o[0] == 'P') {
		P(o[2]);
	}
}

string Editor::print() {
	string t;
	for (list<char>::iterator tlt = s.begin(); tlt != s.end(); tlt++) {
		t += *tlt;
	}
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	list<char> l;
	string s;
	int n;

	getline(cin, s);
	cin >> n;
	cin.ignore();

	for (int i = 0; i < s.size(); i++) {
		l.push_back(s[i]);
	}
	Editor editor(l);

	for (int i = 0; i < n; i++) {
		string tmp;
		getline(cin, tmp);
		editor.input(tmp);
	}
	for (list<char>::iterator tlt = l.begin(); tlt != l .end(); tlt++) {
		cout << *tlt;
	}
	cout << endl;
	
}
