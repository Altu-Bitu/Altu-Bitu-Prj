#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> vec;
map<int, long long> m;

int main() {
    int N, K, p;
    long long result = 0;

    cin >> N >> K;

    vec.assign(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> p;
        vec[i] = vec[i - 1] + p;
    }

    for (int i = 1; i <= N; i++) {
        if (vec[i] == K)
            result++;

        result += m[vec[i] - K];
        m[vec[i]]++;
    }

    cout << result;
}