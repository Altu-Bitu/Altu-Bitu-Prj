#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> input;
vector<int> res;

void backtracking(int len) {
    if (len == M) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        return;
    }

    int pre = -1;
    for (int i = 0; i < N; i++) {
        if (pre == input[i])
            continue;
        pre = input[i];
        res.push_back(input[i]);
        backtracking(len + 1);
        res.pop_back();
    }
    return;
}

int main() {
    cin >> N >> M;
    for (int x, i = 0; i < N; i++) {
        cin >> x;
        input.push_back(x);
    }

    sort(input.begin(), input.end());
    backtracking(0);
    return 0;
}