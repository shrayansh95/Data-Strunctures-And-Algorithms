#include<bits/stdc++.h>
using namespace std;

int prims(int n, vector<pair<int, int>> adj[]) {
	int mini, cost = 0;
	vector<int> key(n, INT_MAX);
	vector<bool> MST(n , false);
	vector<int> parent(n, -1);
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	key[0] = 1;
	pq.push({0, 0});
	while (!pq.empty()) {
		mini = pq.top().second;
		pq.pop();
		if (MST[mini])
			continue;
		MST[mini] = true;
		cost += key[mini];
		for (auto it : adj[mini]) {
			if (!MST[it.first] and key[it.first] > it.second) {
				key[it.first] = it.second;
				pq.push({key[it.first], it.first});
				parent[it.first] = mini;
			}
		}
	}
	for (int i = 1; i < n; i++)
		cout << parent[i] << "--" << i << "\n";
	return cost;
}

int main() {
	int u, v, w, n, m;
	cin >> n >> m;
	vector<pair<int, int>> adj[n];
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	int cost = prims(n, adj);
	cout << cost << "\n";
	return 0;
}