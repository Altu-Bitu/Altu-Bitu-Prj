//ÇÊ¼ö 13458¹ø
#include <iostream>
#define MAX 1000000

using namespace std;

int A[MAX];
int B, C;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	cin >> B >> C;

	long long sum = 0;
	for (int i = 0; i < N; ++i)
	{
		int k = A[i] - B;

		sum++;
		if (k > 0) {
			if (k <= C) {
				sum++;
			}
			else {
				int t = (k / C);
				int re = (k % C);
				if (re != 0) {
					t += 1;
				}
				sum += t;
			}
		}
	}
	cout << sum;
	return 0;
}