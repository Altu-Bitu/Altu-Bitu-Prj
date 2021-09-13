#include <iostream>
#include <cmath>

using namespace std;

void sum(string& str1, string& str2, string& result) {
	int s1, s2;
	int len1 = str1.size(), len2 = str2.size();
	int c = 0;

	while (len1 > 0 || len2 > 0){
		s1 = 0; s2 = 0;

		if (len1 > 0)
			s1 = str1[--len1] - '0';

		if (len2 > 0)
			s2 = str2[--len2] - '0';
	
		int sum = s1 + s2 + c;
		c = sum / 10;
		sum %= 10;
		result += sum + '0';
	}

	if (c > 0) 
		result += c + '0';

	for (int i = result.length() - 1; i >= 0; i--)
		cout << result[i];
}

int main() {
	string A, B, result = "";
	cin >> A >> B;
	sum(A, B, result);

	return 0;
}
