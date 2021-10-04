#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) 
		return a;
	else 
		return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;

        vector<int> vec(n);
        for (int i = 0; i < vec.size(); i++) {
            cin >> vec[i];
        }

        long long sum = 0;

        for (int j = 0; j < vec.size() - 1; j++) {
            for (int k = j + 1; k < vec.size(); k++) {
                sum += gcd(vec[j], vec[k]);
            }
        }
        cout << sum << "\n";
    }
}