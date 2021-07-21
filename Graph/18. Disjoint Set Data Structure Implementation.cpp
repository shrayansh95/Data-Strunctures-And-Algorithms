#include<bits/stdc++.h>
using namespace std;

class disjointSet {
	vector<int> parent, rank;
	int n;
public:
	disjointSet(int n) {
		this->n = n;
		parent.resize(n);
		rank.resize(n);
		makeSet();
	}

	void makeSet() {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}

	int findPar(int node) {
		if (node == parent[node]) {
			return node;
		}
		parent[node] = findPar(parent[node]);
		return parent[node];
	}

	void Union(int x, int y) {
		int u = findPar(x);
		int v = findPar(y);
		// Same Set
		if (u == v) {
			return;
		}
		if (rank[u] > rank[v]) {
			parent[v] = u;
		} else if (rank[v] > rank[u]) {
			parent[u] = v;
		} else {
			parent[u] = v;
			++rank[u];
		}
	}
};

int main() {
	int n;
	cin >> n;
	disjointSet dsu(n);
	if (dsu.findPar(2) == dsu.findPar(3)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	dsu.Union(0, 2);
	dsu.Union(4, 2);
	dsu.Union(3, 1);
	if (dsu.findPar(1) == dsu.findPar(3)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}