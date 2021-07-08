#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int src, vector<int> adj[]) {
	vector<int> distance(n, INT_MAX);
	queue<int> q;
	distance[src] = 0;
	q.push(src);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i : adj[node]) {
			if (distance[i] > distance[node] + 1) {
				distance[i] = distance[node] + 1;
				q.push(i);
			}
		}
	}
	return distance;
}

int main() {
	int n, m;
	cin >> n >> m;
	int u, v;
	vector<int> adj[n];
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int src;
	cin >> src;
	int dest;
	cin >> dest;
	vector<int> ans = shortestPath(n, src, adj);
	cout << ans[dest] << "\n";
	return 0;
}