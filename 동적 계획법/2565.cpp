#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[102];

int main() {
	int N, A, B;
	int result = 0;
	vector<pair<int, int>> v;

	cin >> N;
	v.emplace_back(0, 0);
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		v.emplace_back(A, B);
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) {
				if (dp[j] >= dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
		}
		result = max(result, dp[i]);
	}

	cout << N - result << endl;
	return 0;
}