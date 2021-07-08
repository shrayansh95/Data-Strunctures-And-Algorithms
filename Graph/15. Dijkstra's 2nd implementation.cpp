#include <bits/stdc++.h>
using namespace std;

int mini(int n, vector<int> distance, vector<int> visited) {
	int minIndex, minVal = INT_MAX;
	for (int i = 1; i <= n; i++) {
		if (!visited[i] and minVal >= distance[i]) {
			minVal = distance[i];
			minIndex = i;
		}
	}
	return minIndex;
}

vector<int> dijkstras(int n, int src, vector<pair<int, int>> adj[]) {
	vector<int> distance(n + 1, INT_MAX);
	vector<int> visited(n + 1, 0);
	distance[src] = 0;
	for (int i = 1; i <= n; i++) {
		int it = mini(n, distance, visited);
		visited[it] = 1;
		for (auto v : adj[it]) {
			if (!visited[v.first] and distance[v.first] > distance[it] + v.second)
				distance[v.first] = distance[it] + v.second;
		}
	}
	return distance;
}

int main() {
	int n, m;
	cin >> n >> m;
	int u, v, w;
	vector<pair<int, int>> adj[n + 1];
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	int src;
	cin >> src;
	vector<int> ans = dijkstras(n, src, adj);
	for (int i : ans) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}