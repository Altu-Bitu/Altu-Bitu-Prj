//¼±ÅÃ 1431¹ø
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int strsum(string s) {
    int len = s.length();
    int sum = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] - '0' <= 9 && s[i] - '0' >= 0) {
            sum += s[i] - '0';
        }
    }

    return sum;
}

bool cmp(string str1, string str2)
{
    if (str1.length() != str2.length()) {
        return str1.length() < str2.length();
    }

    else {
        if (strsum(str1) != strsum(str2)) {
            return strsum(str1) < strsum(str2);
        }

        else 
            return str1 < str2;
    }
}

vector<string> v;

int main() {
    int n;
    cin >> n;
    string str;

    for (int i = 0; i < n; i++) {
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << v[i] << "\n";
    }
}