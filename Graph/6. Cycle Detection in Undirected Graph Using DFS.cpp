#include<bits/stdc++.h>
using namespace std;

bool cycleDfs(int i, vector<int> adj[], vector<int>& visit, int parent) {
	visit[i] = 1;
	for (int it : adj[i]) {
		if (!visit[it]) {
			if (cycleDfs(it, adj, visit, i))
				return true;
		} else if (it != parent) {
			return true;
		}
	}
	return false;
}

bool detectCycle(int n, vector<int> adj[]) {
	vector<int> visit(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			bool ok = cycleDfs(i, adj, visit, -1);
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
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (detectCycle(n, adj))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}