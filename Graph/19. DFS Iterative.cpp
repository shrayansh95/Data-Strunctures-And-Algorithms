#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> adj[n];
	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	int src;
	cin >> src;
	stack<pair<int, string>> st;
	vector<int> visit(n, 0);
	st.push({src, to_string(src)});
	while (!st.empty()) {
		pair<int, string> node = st.top();
		st.pop();
		if (visit[node.first])
			continue;
		visit[node.first] = 1;
		cout << node.first << "@" << node.second << endl;
		for (auto it : adj[node.first]) {
			if (!visit[it.first]) {
				st.push({it.first, node.second + to_string(it.first)});
			}
		}
	}
	return 0;
}