#include<bits/stdc++.h>
using namespace std;

int main() {
	cout << "Max Heap\n";
	priority_queue<int> pq;
	pq.push(45);
	pq.push(23);
	pq.push(13);
	pq.push(98);
	cout << "Maximum Element = " << pq.top() << "\n";

	cout << "The elements in the queue in decescending order are : ";
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << "\n";

	cout << "Min Heap\n";
	priority_queue<int, vector<int>, greater<int>> pq1;
	pq1.push(45);
	pq1.push(23);
	pq1.push(13);
	pq1.push(98);
	cout << "Minimumm Element = " << pq1.top() << "\n";

	cout << "The elements in the queue in increasing order are : ";
	while (!pq1.empty()) {
		cout << pq1.top() << " ";
		pq1.pop();
	}
	cout << "\n";
}