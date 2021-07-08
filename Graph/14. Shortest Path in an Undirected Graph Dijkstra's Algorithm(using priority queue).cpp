#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstras(int n, int src, vector<pair<int, int>> adj[]) {
	vector<int> distance(n + 1, INT_MAX);
	distance[src] = 0;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	pq.push({0, src});
	while  (!pq.empty()) {
		pair<int, int> node = pq.top();
		pq.pop();
		for (auto i : adj[node.second]) {
			if (distance[i.first] > distance[node.second] + i.second) {
				distance[i.first] = distance[node.second] + i.second;
				pq.push({distance[i.first], i.first});
			}
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