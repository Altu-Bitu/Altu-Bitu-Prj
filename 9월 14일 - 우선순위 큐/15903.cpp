#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	long long res = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		long long s; 
		cin >> s; 
		pq.push(s);
	}

	for (int i = 0; i < m; i++) {
		long long s1 = pq.top(); 
		pq.pop();
		long long s2 = pq.top(); 
		pq.pop();

		pq.push(s1 + s2);
		pq.push(s1 + s2);
	}
		
	while (!pq.empty()) {
		res += pq.top(); 
		pq.pop();
	}

	cout << res;
	return 0;
}