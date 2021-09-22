#include <iostream>
#include <cmath>

using namespace std;

int gcdFunc(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcdFunc(b, a % b);
}

int main() {
	int gcd, lcm, x, temp;
	long long int res1 = 1, res2 = 1; 

	cin >> gcd >> lcm;

	lcm = lcm / gcd;

	for (int i = sqrt(lcm); i >= 1; i--) {
		if (lcm % i == 0 && gcdFunc(i, lcm / i) == 1) {
			x = i;
			break;
		}
	}
	
	res1 = gcd * x;
	res2 = gcd * (lcm / x);

	if (res1 > res2) {
		temp = res1;
		res1 = res2;
		res2 = temp;
	}

	cout << res1 << ' ' << res2;
}