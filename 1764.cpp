#include <iostream>
#include <algorithm>
#include <set>

using namespace  std;
set<string> dbj, result;

int main() {
    int N, M, cnt = 0;
    char name[21];
    cin >> N >> M;

    while (N--) { 
        cin >> name;
        dbj.insert(name);
    }

    while (M--) {
        cin >> name; 
        if (dbj.find(name) != dbj.end()) {
            cnt++;
            result.insert(name);
        }
    }

    cout << cnt << '\n';

    for (const auto& iter : result) 
        cout << iter << '\n';

    return 0;
}