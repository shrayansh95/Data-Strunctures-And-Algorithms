#include<bits/stdc++.h>
using namespace std;

bool dfs(int i, vector<int> adj[], vector<int>& visit, vector<int>& dfsVisit) {
	visit[i] = 1;
	dfsVisit[i] = 1;
	for (int it : adj[i]) {
		if (!visit[it]) {
			if (dfs(it, adj, visit, dfsVisit))
				return true;
		} else if (dfsVisit[it]) {
			return true;
		}
	}
	dfsVisit[i] = 0;
	return false;
}

bool cycleDirected(int n, vector<int> adj[]) {
	vector<int> dfsVisit(n + 1, 0);
	vector<int> visit(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			bool ok = dfs(i, adj, visit, dfsVisit);
			if (ok)
				return true;
		}
	}
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n + 1];
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v); B
	}
	if (cycleDirected(n, adj))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}