#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> adj[n +  1];
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < n + 1; i++) {
		cout << i << "\t";
		for (int j = 0; j < adj[i].size(); j++) {
			cout << adj[i][j] << "\t";
		}
		cout << "\n";
	}
}