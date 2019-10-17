/*
 ���μ��� �����ϱ�
 ��Ʈ��ŷ ����
 1) �ִ� 5 ^ 11 �� �ð����⵵
 2) 4 ���� Ž���� �������� �ʴ� ���� �����ϱ�
 3) Ž�� ���� : ��,��,��,�Ͽ� ���� ���� 0���� �ƴ��� �Ǻ�  <- 2 ���� �迭 Ž���� �Ű������� x,y �� �Ѱ��ִ� ���� ���
				������ �Լ��� �� ������ ���� �������ִ� ���� ���
 4) ���� ���� ���� �� �� üũ ���� : Ž�� ������ ���� ����ϳ� �Լ� �Ű� ������ type�� ���� �޾� map[i][j] = (type == 0) ? 2 : 0; �� ���ִ� �͵� ���
 5) dfs�Լ��� ī���� ���� ����
*/

#include <stdio.h>
#include <vector>



using namespace std;

int n, minLeng = 2147000000, maxCnt = -1;
int pnum;


pair<int, bool> check(int P, int dir,vector<pair<int,int>>& ploc, vector<vector<int>>& ch) {

	bool flag = true;
	int length = 0;
	//�� ���� �������� Ž��
	if (dir == 1) {
		for (int i = ploc[P].first - 1; i >= 0; --i) {
			if (ch[i][ploc[P].second] == 1) {
				flag = false;
				break;
			}
			else length++;
		}
	}
	//�� ���� �������� Ž��
	else if (dir == 2) {
		for (int i = ploc[P].second + 1; i < n; ++i) {
			if (ch[ploc[P].first][i] == 1) {
				flag = false;
				break;
			}
			else length++;
		}
	}
	//�� ����
	else if (dir == 3) {
		for (int i = ploc[P].first + 1; i < n; ++i) {
			if (ch[i][ploc[P].second] == 1) {
				flag = false;
				break;
			}
			else length++;
		}
	}
	//�� ����
	else if (dir == 4) {
		for (int i = ploc[P].second - 1; i >= 0; --i) {
			if (ch[ploc[P].first][i] == 1) {
				flag = false;
				break;
			}
			else length++;
		}
	}

	if (flag) {
		//dir ���� ch�迭 1�� ����
		if (dir == 1) {
			for (int i = ploc[P].first - 1; i >= 0; --i) {
				ch[i][ploc[P].second] = 1;
			}
			return make_pair(length, true);
		}
		else if (dir == 2) {
			for (int i = ploc[P].second + 1; i < n; ++i) {
				ch[ploc[P].first][i] = 1;
			}
			return make_pair(length, true);
		}
		else if (dir == 3) {
			for (int i = ploc[P].first + 1; i < n; ++i) {
				ch[i][ploc[P].second] = 1;
			}
			return make_pair(length, true);
		}
		else if (dir == 4) {
			for (int i = ploc[P].second - 1; i >= 0; --i) {
				ch[ploc[P].first][i] = 1;
			}
			return make_pair(length, true);
		}
	}
	else {
		return make_pair(0, false);
	}
}

void release(int P, int dir, vector<pair<int, int>>& ploc, vector<vector<int>>& ch) {
	if (dir == 1) {
		for (int i = ploc[P].first - 1; i >= 0; --i) {
			ch[i][ploc[P].second] = 0;
		}
	}
	else if (dir == 2) {
		for (int i = ploc[P].second + 1; i < n; ++i) {
			ch[ploc[P].first][i] = 0;
		}
	}
	else if (dir == 3) {
		for (int i = ploc[P].first + 1; i < n; ++i) {
			ch[i][ploc[P].second] = 0;
		}
	}
	else if (dir == 4) {
		for (int i = ploc[P].second - 1; i >= 0; --i) {
			ch[ploc[P].first][i] = 0;
		}
	}
}


void dfs(int P, int sum, int cnt,vector<pair<int,int>>& ploc, vector<vector<int>>& ch) {
	pair<int, int> res;
	if (P == pnum) {
		if (maxCnt < cnt) {
			maxCnt = cnt;
			minLeng = sum;
		}
		else if (maxCnt == cnt) {
			if (minLeng > sum) minLeng = sum;
		}
	}
	else {
		for (int i = 1; i <= 4; i++) {
			res = check(P, i,ploc,ch);
			if (res.second) {
				dfs(P + 1, sum + res.first, cnt + 1,ploc,ch);
				release(P, i,ploc,ch);
			}
		}
		dfs(P + 1, sum, cnt, ploc, ch);
	}
}


int main() {
	int t;
	scanf("%d", &t);

	for (int test_case = 1; test_case <= t; test_case++) {
		scanf("%d", &n);
		vector<vector<int>> ch;
		vector<pair<int, int>> ploc;
		for (int i = 0; i < n; i++) {
			vector<int> element(n, 0);
			ch.push_back(element);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0, t; j < n; j++) {
				scanf("%d", &t);
				if (t == 1) {
					ch[i][j] = 1;
					if (i == 0 || i == n - 1 || j == 0 || j == n - 1) continue;
					ploc.push_back(make_pair(i, j));
					pnum++;
				}
			}
		}
		dfs(0, 0, 0,ploc,ch);
		printf("#%d %d\n", test_case, minLeng);

		minLeng = 2147000000;
		maxCnt = -1;
		pnum = 0;
	}
}