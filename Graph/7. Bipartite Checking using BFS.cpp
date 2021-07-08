#include<bits/stdc++.h>
using namespace std;

bool bfs(int i, vector<int> adj[], vector<int>& color) {
	color[i] = 0;
	queue<int> q;
	q.push(i);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int it : adj[node]) {
			if (color[it] == -1) {
				color[it] = color[node] ^ 1;
				q.push(it);
			} else if (color[it] == color[node]) {
				return false;
			}
		}
	}
	return true;
}

bool isBipartite(int n, vector<int> adj[]) {
	vector<int> color(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		if (color[i] == -1) {
			bool ok = bfs(i, adj, color);
			if (!ok)
				return false;
		}
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n + 1];
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (isBipartite(n, adj))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}