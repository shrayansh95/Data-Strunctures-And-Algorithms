#include<bits/stdc++.h>
using namespace std;

bool cycleBfs(int i, vector<int> adj[], vector<int> &visit) {
	visit[i] = 1;
	queue<pair<int, int>> q;
	q.push({i, -1});
	while (!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();
		for (int it : adj[node.first]) {
			if (!visit[it]) {
				q.push({it, node.first});
				visit[it] = 1;
			} else if (it != node.second) {
				return true;
			}
		}
	}
	return false;
}

bool detectCycle(int n, vector<int> adj[]) {
	vector<int> visit(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			bool ok = cycleBfs(i, adj, visit);
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