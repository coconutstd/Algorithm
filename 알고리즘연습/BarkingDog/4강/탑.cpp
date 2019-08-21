#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//first�� Ÿ���� ���� second�� Ÿ���� ����
typedef pair<int, int> TowerInfo;

class Tower
{
public:
	Tower() {}
	void ReceivedTower(const vector<int>& Input);
};

void Tower::ReceivedTower(const vector<int>& Input)
{
	stack<TowerInfo> st;
	vector<int> ans(Input.size()+1,0);
	st.push(make_pair(*(Input.end() - 1), Input.size()));
	for (int i = Input.size() - 2; i >= 0; --i) {
		//�������� ���ϴ� ���
		if (st.top().first > Input[i]) {
			st.push(make_pair(Input[i], i + 1));
		}
		//�����ϴ� ���
		else
		{
			while (!st.empty() && st.top().first < Input[i]) 
			{
				ans[st.top().second] = i + 1;
				st.pop();
			}	
			st.push(make_pair(Input[i], i + 1));
		}
	}
	for (int i = 1; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	vector<int> Input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		Input.push_back(t);
	}
	Tower tower;
	tower.ReceivedTower(Input);
}