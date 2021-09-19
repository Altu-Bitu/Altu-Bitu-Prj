#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(const pair<string, int>& p1, const pair<string, int>& p2) {
	if (p1.second != p2.second) {
		return p1.second > p2.second;
	}

	if (p1.first.size() != p2.first.size()) {
		return p1.first.size() > p2.first.size();
	}

	return p1.first < p2.first;
}

int main() {
	int N, M;
	string word;
	map<string, int> cnt;

	cin >> N >> M;

	while (N--){
		cin >> word;

		if (M <= word.size()) {
			cnt[word]++;
		}
	}

	vector<pair<string, int>> v(cnt.begin(), cnt.end());

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << '\n';
	}
}