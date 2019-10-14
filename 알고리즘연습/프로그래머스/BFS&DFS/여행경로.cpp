#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<string>> list;
void dfs(vector<vector<string>>& tickets, vector<int>& visit, string end, int cnt, vector<string>& path) {

	path.push_back(end);

	if (cnt == tickets.size()) {
		list.push_back(path); return;
	}
	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == end && visit[i] == 0) {
			visit[i] = 1;
			dfs(tickets, visit, tickets[i][1], cnt + 1, path);
			visit[i] = 0;
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;

	for (int i = 0; i < tickets.size(); i++) {
		vector<int> visit(tickets.size(), 0);
		vector<string> path;
		string start = tickets[i][0];
		if (start == "ICN") {
			visit[i] = 1;
			path.push_back(start);
			dfs(tickets, visit, tickets[i][1], 1, path);
		}
	}
	sort(list.begin(), list.end());
	for (int i = 0; i < list.size(); i++) {
		for (int j = 0; j < list[i].size(); j++) {
			cout << list[i][j] << " ";
		}
		cout << endl;
	}

	return list[0];
}