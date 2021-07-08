#include <bits/stdc++.h>
using namespace std;

void prims(int n, vector<pair<int, int>> adj[]) {
	vector<int> key(n, INT_MAX);
	key[0] = 0;
	vector<bool> MST(n, false);
	vector<int> parent(n , -1);
	for (int i = 0; i < n - 1; i++) {
		int mini, minVal = INT_MAX;
		for (int j = 0; j < n; j++) {
			if (!MST[j] and key[j] < minVal) {
				minVal = key[j];
				mini = j;
			}
		}
		MST[mini] = true;
		for (auto it : adj[mini]) {
			if (!MST[it.first] and key[it.first] > it.second) {
				key[it.first] = it.second;
				parent[it.first] = mini;
			}
		}
	}
	for (int it : parent)
		cout << it << " ";
	cout << endl;
}

int main() {
	int n, m;
	cin >> n >> m;
	int u, v, w;
	vector<pair<int, int>> adj[n];
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	prims(n, adj);
	return 0;
}