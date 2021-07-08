#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<pair<int, int>> adj[], vector<int>& visit, stack<int>& topoSort) {
	visit[i] = 1;
	for (auto it : adj[i]) {
		if (!visit[it.first]) {
			dfs(it.first, adj, visit, topoSort);
		}
	}
	topoSort.push(i);
}

vector<int> shortestPath(int n, int src, vector<pair<int, int>> adj[]) {
	stack<int> topoSort;
	vector<int> visit(n, 0);
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			dfs(i, adj, visit, topoSort);
		}
	}
	vector<int> distance(n, INT_MAX);
	distance[src] = 0;
	while (!topoSort.empty()) {
		int node = topoSort.top();
		topoSort.pop();
		if (distance[node] != INT_MAX) {
			for (auto i : adj[node]) {
				if (distance[i.first] > distance[node] + i.second) {
					distance[i.first] = distance[node] + i.second;
				}
			}
		}
	}
	return distance;
}

int main() {
	int n, m;
	cin >> n >> m;
	int u, v, w;
	vector<pair<int, int>> adj[n];
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	int src;
	cin >> src;
	int dest;
	cin >> dest;
	vector<int> ans = shortestPath(n, src, adj);
	for (int i : ans) {
		cout << i << " ";
	}
	cout << endl;
	cout << ans[dest] << "\n";
	return 0;
}