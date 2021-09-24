#include <iostream>

using namespace std;

int fac(int x) {
	int res = 1;
	for (int i = x; i > 0; i--) {
		res *= i;
	}
	return res;
}

int main() {
	int N, K;
	cin >> N >> K;

	int result = fac(N) / (fac(K) * fac(N - K));
	cout << result;
}