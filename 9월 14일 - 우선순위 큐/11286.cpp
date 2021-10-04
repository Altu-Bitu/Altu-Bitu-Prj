#include <iostream>
#include <queue>

using namespace std;

class cmp {
public:
    int operator() (int a, int b) {
        if (abs(a) != abs(b)) {
            return abs(a) > abs(b);
        }
        return a > b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, x, abs_min;
    priority_queue<int, vector<int>, cmp> arr;

    cin >> N;

    while (N--) {
        cin >> x;
        if (x != 0) 
            arr.push(x);
        else {
            if (arr.empty()) {
                abs_min = 0;
            }
            else {
                abs_min = arr.top();
                arr.pop();
            }
            cout << abs_min << '\n';
        }
    }
    return 0;
}