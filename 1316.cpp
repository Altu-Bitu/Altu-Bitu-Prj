#include <iostream>
using namespace std;

int main() {
	int n;
	string s;
	
	cin >> n;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		cin >> s;
		int len = s.length();
		bool flag = true;

		for (int j = 0; j < len; j++) {
			for (int k = 0; k < j; k++) {
				if (s[j] != s[j - 1] && s[j] == s[k]) {
					flag = false;
					break;
				}
			}
		}
		if (flag)
			cnt++;
	}
	cout << cnt;
	return 0;
}
