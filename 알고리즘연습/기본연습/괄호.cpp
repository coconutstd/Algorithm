#include <cstdio>
#include <memory.h>
#include <stack>
using namespace std;
stack<char> st;
int T;
char s[51];
int l_cnt,r_cnt;
int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%s", s);
		for (char x : s) {
			if (x == '\0') {
				continue;
			}
			if (x == '(') {
				l_cnt++;
				st.push(x);
			}
			else if (x == ')') {
				r_cnt++;
				if (!st.empty()) {
					st.pop();
				}
			}
		}
		if (st.empty() && l_cnt == r_cnt) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

		while (!st.empty()) {
			st.pop();
		}
		r_cnt = l_cnt  = 0;
		memset(s, '\0', sizeof(s));
	}

}