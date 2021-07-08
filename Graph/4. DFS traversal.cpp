#include<bits/stdc++.h>
using namespace std;

void DFS(int i, vector<int> &visit, vector<int> adj[], vector<int> &dfs) {
	visit[i] = 1;
	dfs.push_back(i);
	for (int it : adj[i]) {
		if (!visit[it])
			DFS(it, visit, adj, dfs);
	}
}

vector<int> dfstravel(int V, vector<int> adj[]) {
	vector<int> dfs;
	vector<int> visit(V + 1, 0);

	for (int i = 1; i <= V; i++) {
		if (!visit[i])
			DFS(i, visit, adj, dfs);
	}
	return dfs;
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

	vector<int> dfs = dfstravel(n, adj);
	for (int i = 0; i < dfs.size(); i++)
		cout << dfs[i] << " ";
	cout << "\n";
	return 0;
}