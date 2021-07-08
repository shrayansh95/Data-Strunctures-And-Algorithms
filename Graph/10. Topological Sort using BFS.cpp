#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int n, vector<int> adj[]) {
	vector<int> ans;
	vector<int> indegree(n, 0);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		for (int it : adj[i])
			++indegree[it];
	}

	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		ans.push_back(node);
		for (int it : adj[node]) {
			--indegree[it];
			if (indegree[it] == 0)
				q.push(it);

		}
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