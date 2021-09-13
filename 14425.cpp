#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<string> s;

int main() {
    int N, M, cnt = 0;
    char c[501];

    cin >> N >> M;

    while (N--) {
        cin >> c;
        s.insert(c);
    }

    while (M--) {
        cin >> c;
        if (s.find(c) != s.end()) 
            cnt++;
    }

    cout << cnt;
    return 0;
}