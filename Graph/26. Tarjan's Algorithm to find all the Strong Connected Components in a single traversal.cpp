#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& in, vector<int>& low, vector<bool>& inStack, stack<int>& st, int& timer, vector<int> adj[]) {
	in[node] = low[node] = timer;
	++timer;
	st.push(node);
	inStack[node] = true;
	for (int child : adj[node]) {
		if (in[child] == -1) {
			dfs(child, in, low, inStack, st, timer, adj);
			low[node] = min(low[node], low[child]);
		} else if (inStack[child]) {
			low[node] = min(low[node], in[child]);
		}
	}

	if (low[node] == in[node]) {
		cout << "SCC: ";
		while (st.top() != node) {
			cout << st.top() << " ";
			inStack[st.top()] = false;
			st.pop();
		}
		cout << st.top() << "\n";
		inStack[st.top()] = false;
		st.pop();
	}
}

void trajansAlgo(int n , vector<int> adj[]) {
	int timer = 0;
	vector<int> in(n, -1), low(n, -1);
	vector<bool> inStack(n, false);
	stack<int> st;

	for (int i = 0; i < n; i++) {
		if (in[i] == -1)
			dfs(i, in, low, inStack, st, timer, adj);
	}
}

int main() {
	int u, v, n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
	}

	trajansAlgo(n, adj);

	return 0;
}