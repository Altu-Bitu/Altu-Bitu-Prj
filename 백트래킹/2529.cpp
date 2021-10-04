#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int k, check[10];
char input[10];
vector<string> vec;

bool ok(char x, char y, char op) {
	if (x < y && op == '<') {
		return true;
	}
	if (x > y && op == '>') {
		return true;
	}
	return false;
}

void go(int idx, string num) {
	if (idx == k + 1) {
		vec.push_back(num); 
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (check[i]) 
			continue;

		if (idx == 0 || ok(num[idx - 1], i + '0', input[idx - 1])) {
			check[i] = 1;
			go(idx + 1, num + to_string(i));
			check[i] = 0;
		}
	}
	return;
}

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> input[i];
	}
	go(0, "");
	sort(vec.begin(), vec.end());
	cout << vec[vec.size() - 1] << "\n" << vec[0] << "\n";
}