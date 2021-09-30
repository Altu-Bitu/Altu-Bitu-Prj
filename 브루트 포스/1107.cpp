#include <iostream>

using namespace std;

bool mArr[11];

int check(int n) {
    if (n == 0) {
        if (mArr[0]) 
            return 0;
        else 
            return 1;
    }

    int len = 0;

    while (n > 0) {
        if (mArr[n % 10]) 
            return 0;
        n = n / 10;
        len++;
    }
    return len;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        mArr[x] = true;
    }

    int res = N - 100;

    if (res < 0)
        res = -res;

    for (int i = 0; i <= 10000000; i++) {
        int len = check(i);
        if (len > 0) {
            int pr = abs(i - N);
            if (res > pr + len) {
                res = pr + len;
            }
        }
    }

    cout << res;
}