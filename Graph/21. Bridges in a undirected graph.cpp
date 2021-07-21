#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int>& tin, vector<int>& low, vector<int>& visit, int& timer, int parent) {
	visit[node] = 1;
	tin[node] = low[node] = timer++;
	for (int child : adj[node]) {
		if (parent == child)
			continue;
		if (visit[child]) {
			low[node] = min(low[node], tin[child]);
		} else {
			dfs(child, adj, tin, low, visit, timer, node);
			if (low[child] > tin[node]) {
				cout << node << " " << child << "\n";
			}
			low[node] = min(low[node], low[child]);
		}
	}
}

int main() {
	int n, m, u, v;
	cin >> n >> m;
	vector<int> adj[n + 1];
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int timer = 0;
	vector<int> tin(n + 1), low(n + 1), visit(n + 1, 0);
	dfs(1, adj, tin, low, visit, timer, -1);
	return 0;
}