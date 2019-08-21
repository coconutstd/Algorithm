#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Bracket
{
public:
	Bracket() {}
	int ValueOfBracket(const string& s);
};

int Bracket::ValueOfBracket(const string& s)
{
	stack<char> st;
	int ans = 0, val = 1;
	if (s[0] == ')' || s[0] == ']') return 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(') {
			val *= 2;
			st.push(s[i]);
		}
		else if (s[i] == '[')
		{
			val *= 3;
			st.push(s[i]);
		}
		else if (s[i] == ')' && (st.empty() || st.top() != '('))
		{
			return 0;
		}
		else if (s[i] == ']' && (st.empty() || st.top() != '['))
		{
			return 0;
		}
		else if (s[i] == ')')
		{
			if (s[i - 1] == '(') 
			{
				ans += val;
			}
			st.pop();
			val /= 2;
		}
		else if (s[i] == ']')
		{
			if (s[i - 1] == '[')
			{
				ans += val;
			}
			st.pop();
			val /= 3;
		}
	}
	if (st.empty()) {
		return ans;
	}
	else {
		return 0;
	}
}

int main()
{
	string s;
	cin >> s;
	Bracket bracket;
	cout << bracket.ValueOfBracket(s) << "\n";
}