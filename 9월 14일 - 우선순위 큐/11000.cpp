#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> sugang;

int main() {
    int N;
    int i = 0;
    priority_queue<int, vector<int>, greater<>> pq;

    cin >> N;

    sugang.assign(N, {});
    for (int i = 0; i < N; i++) {
        cin >> sugang[i].first >> sugang[i].second;
    }

    sort(sugang.begin(), sugang.end());

    pq.push(sugang[i++].second);

    while (i < sugang.size()) {
        if (pq.top() <= sugang[i].first)
            pq.pop();
        pq.push(sugang[i++].second);
    }

    cout << pq.size();
    return 0;
}