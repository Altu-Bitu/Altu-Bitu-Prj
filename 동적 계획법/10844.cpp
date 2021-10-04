#include <iostream>
#define M 1000000000

using namespace std;

int dp[101][10];

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int j = 2; j <= N; j++) {
        for (int k = 0; k <= 9; k++) {
            if (k == 0) {
                dp[j][k] = dp[j - 1][k + 1] % M;
            }
            else if (k == 9) {
                dp[j][k] = dp[j - 1][k - 1] % M; 
            }
            else {
                dp[j][k] = (dp[j - 1][k - 1] + dp[j - 1][k + 1]) % M;
            }
        }
    }

    int sum = 0;

    for (int t = 0; t <= 9; t++) {
        sum = (sum + dp[N][t]) % M;
    }

    cout << sum << "\n";

    return 0;
}