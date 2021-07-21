#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int& timer, vector<int> adj[], vector<int>& visit, vector<int>& tin, vector<int>& low, vector<int>& isArticulation) {
	visit[node] = 1;
	low[node] = tin[node] = timer++;
	int childNodes = 0;
	for (int child : adj[node]) {
		if (child == parent)
			continue;
		if (visit[child])
			low[node] = min(low[node], tin[child]);
		else {
			dfs(child, node, timer, adj, visit, tin, low, isArticulation);
			low[node] = min(low[node], low[child]);
			if (tin[node] <= low[child] and parent != -1)
				isArticulation[node] = 1;
			++childNodes;
		}
	}
	if (parent == -1 and childNodes > 1)
		isArticulation[node] = 1;
}

void printArticulationPoint(int n, vector<int> adj[]) {
	vector<int> visit(n + 1, 0);
	vector<int> tin(n + 1), low(n + 1), isArticulation(n + 1, 0);
	int timer = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			dfs(i, -1, timer, adj, visit, tin, low, isArticulation);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (isArticulation[i])
			cout << i << "\n";
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
	printArticulationPoint(n, adj);
	return 0;
}