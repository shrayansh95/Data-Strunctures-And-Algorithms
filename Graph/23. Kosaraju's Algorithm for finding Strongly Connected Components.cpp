#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<int> adj[], vector<int>& visit, stack<int>& topo) {
	visit[node] = 1;
	for (int child : adj[node]) {
		if (!visit[child]) {
			topoSort(child, adj, visit, topo);
		}
	}
	topo.push(node);
}

void revDfs(int node, vector<int> adj[], vector<int>& visit) {
	visit[node] = 1;
	cout << node << " ";
	for (int child : adj[node]) {
		if (!visit[child])
			revDfs(child, adj, visit);
	}
}

void kosaraju(int n, vector<int> adj[]) {
	vector<int> visit(n + 1, 0);
	stack<int> topo;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			topoSort(i, adj, visit, topo);
		}
	}

	vector<int> transpose[n + 1];
	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
		for (int child : adj[i]) {
			transpose[child].push_back(i);
		}
	}

	cout << "SCC\n";
	while (!topo.empty()) {
		if (!visit[topo.top()]) {
			revDfs(topo.top(), transpose, visit);
			cout << "\n";
		}
		topo.pop();
	}
}

int main() {
	int u, v, n, m;
	cin >> n >> m;
	vector<int> adj[n + 1];
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
	}
	kosaraju(n, adj);
	return 0;
}