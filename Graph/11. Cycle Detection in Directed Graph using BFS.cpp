#include<bits/stdc++.h>
using namespace std;

bool isCyclic(int n, vector<int> adj[]) {
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

	int cnt = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		++cnt;
		for (int it : adj[node]) {
			--indegree[it];
			if (indegree[it] == 0)
				q.push(it);
		}
	}
	if (cnt == n)
		return true;
	return false;
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
	if (isCyclic(n, adj))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}