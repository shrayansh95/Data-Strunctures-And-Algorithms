#include <bits/stdc++.h>
#define inf 10000000
using namespace std;

void floydWarshall(int n, vector<vector<int>> adj) {
	vector<vector<int>> dist;
	dist = adj;

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][k] == inf or dist[k][j] == inf)
					continue;
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << dist[i][j] << "\t";
		cout << "\n";
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
			if (adj[i][j] == 0 and i != j)
				adj[i][j] = inf;
		}
	}

	floydWarshall(n, adj);

	return 0;
}