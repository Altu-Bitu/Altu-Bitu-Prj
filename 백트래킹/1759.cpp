#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

char str[16];
int L, C;

void backtracking(int position, string s, int vow, int con){
	if (s.size() == L){
		if (vow >= 1 && con >= 2) {
			cout << s << endl;
		}
		return;
	}

	for (int i = position; i <= C; i++){

		if (str[i] == 'a' || str[i] == 'u' || str[i] == 'i' || str[i] == 'o' || str[i] == 'e') {
			backtracking(i + 1, s + str[i], vow + 1, con);
		}
		else {
			backtracking(i + 1, s + str[i], vow, con + 1);
		}
	}
}

int main(){
	cin >> L >> C;

	for (int i = 1; i <= C; i++){
		cin >> str[i];
	}

	sort(str, str + C + 1);
	backtracking(1, "", 0, 0);
	return 0;

}