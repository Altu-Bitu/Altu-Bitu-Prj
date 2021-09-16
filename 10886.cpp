#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N, x;
    string str;
    deque<int> dq;

    cin >> N;

    while (N--) {
        cin >> str;

        if (str == "push_front") {
            cin >> x;
            dq.push_front(x);
            continue;
        }

        if (str == "push_back") {
            cin >> x;
            dq.push_back(x);
            continue;
        }

        if (str == "pop_front") {
            if (dq.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            continue;
        }

        if (str == "pop_back") {
            if (dq.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            continue;
        }

        if (str == "size") {
            cout << dq.size() << "\n";
        }

        if (str == "empty") {
            if (dq.empty()) {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
            continue;
        }

        if (str == "front") {
            if (dq.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << dq.front() << "\n";
            }
            continue;
        }

        if (str == "back") {
            if (dq.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << dq.back() << "\n";
            }
            continue;
        }
    }
}