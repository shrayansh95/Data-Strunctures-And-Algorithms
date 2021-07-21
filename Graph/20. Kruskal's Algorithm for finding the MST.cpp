#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v, wt;
	edge(int u, int v, int wt) {
		this->u = u;
		this->v = v;
		this->wt = wt;
	}
};

struct node {
	int parent;
	int rank;
};

bool comp(struct edge a, struct edge b) {
	return a.wt < b.wt;
}

int findPar(int x, vector<node>& dsu) {
	if (x != dsu[x].parent)
		dsu[x].parent = findPar(dsu[x].parent, dsu);
	return dsu[x].parent;
}

void unionn(int x, int y, vector<node>& dsu) {
	int u = findPar(x, dsu);
	int v = findPar(y, dsu);
	if (dsu[u].rank < dsu[v].rank) {
		dsu[u].parent = v;
	} else if (dsu[u].rank > dsu[v].rank) {
		dsu[v].parent = u;
	} else {
		dsu[v].parent = u;
		++dsu[u].rank;
	}
}

int main() {
	int n, m, u, v, wt;
	cin >> n >> m;
	vector<edge> edges;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> wt;
		struct edge it = edge(u, v, wt);
		edges.push_back(it);
	}

	sort(edges.begin(), edges.end(), comp);

	vector<node> dsu(n);
	for (int i = 0; i < n; i++) {
		dsu[i].rank = 0;
		dsu[i].parent = i;
	}

	int cost = 0;
	vector<pair<int, int>> MST;
	for (auto it : edges) {
		if (findPar(it.u, dsu) != findPar(it.v, dsu)) {
			cost += it.wt;
			MST.push_back({it.u, it.v});
			unionn(it.u, it.v, dsu);
		}
	}

	cout << cost << "\n";
	for (auto it : MST) {
		cout << it.first << " " << it.second << "\n";
	}
	return 0;
}