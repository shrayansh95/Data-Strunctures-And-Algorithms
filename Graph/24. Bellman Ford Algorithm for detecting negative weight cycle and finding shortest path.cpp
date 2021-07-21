#include <bits/stdc++.h>
using namespace std;

struct node {
	int u, v, wt;
	node (int first, int second, int weight) {
		u = first;
		v = second;
		wt = weight;
	}
};

int main() {
	int n, m, u, v, wt;
	cin >> n >> m;
	vector<node> edges;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> wt;
		edges.push_back(node(u, v, wt));
	}

	int src;
	cin >> src;

	int inf = 10000000;
	vector<int> dist(n, inf);
	dist[src] = 0;

	for (int i = 1 ; i <= n - 1; i++) {
		for (auto edge : edges) {
			if (dist[edge.u] + edge.wt < dist[edge.v])
				dist[edge.v] = dist[edge.u] + edge.wt;
		}
	}

	int ok = 0;
	for (auto edge : edges) {
		if (dist[edge.u] + edge.wt < dist[edge.v]) {
			cout << "Negative Cycle Present\n";
			ok = 1;
			break;
		}
	}

	if (!ok) {
		cout << "Negative Cycle Not Present\n";
		for (int i = 0; i < n; i++)
			cout << i << " " << dist[i] << "\n";
	}
	return 0;
}