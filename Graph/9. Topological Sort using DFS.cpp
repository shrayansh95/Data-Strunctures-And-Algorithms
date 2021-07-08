#include<bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> adj[], vector<int>& visit, stack<int>& topoSort) {
	visit[i] = 1;
	for (int it : adj[i]) {
		if (!visit[it])
			dfs(it, adj, visit, topoSort);
	}
	topoSort.push(i);
}

vector<int> topologicalSort(int n, vector<int> adj[])
{
	vector<int> visit(n, 0);
	stack<int> topoSort;
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			dfs(i, adj, visit, topoSort);
		}
	}
	vector<int> ans;
	while (!topoSort.empty()) {
		ans.push_back(topoSort.top());
		topoSort.pop();
	}
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
	}
	vector<int> ans = topologicalSort(n, adj);
	for (int it : ans)
		cout << it << " ";
	cout << endl;
	return 0;
}