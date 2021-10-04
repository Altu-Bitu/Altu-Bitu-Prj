#include <iostream>
#include <queue>

using namespace std;

deque<int> deq[2], ground[2];

int N, M;

int win() {
    if (ground[0].size() && ground[0].front() == 5) 
        return 0;
    if (ground[1].size() && ground[1].front() == 5) 
        return 0;
    if (ground[0].size() && ground[1].size() && ground[0].front() + ground[1].front() == 5) 
        return 1;
    return -1;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        int a, b; 
        cin >> a >> b;
        deq[0].push_front(a);
        deq[1].push_front(b);
    }

    int turn = 0;
    for (int i = 0; i < M; ++i) {
        ground[turn].push_front(deq[turn].front());
        deq[turn].pop_front();

        if (deq[turn].empty()) {
            cout << (turn ? "do" : "su") << '\n';
            return 0;
        }

        int w = win();
        if (w != -1) {
            int l = 1 - w;
            while (ground[l].size()) {
                deq[w].push_back(ground[l].back());
                ground[l].pop_back();
            }
            while (ground[w].size()) {
                deq[w].push_back(ground[w].back());
                ground[w].pop_back();
            }
        }
        turn = 1 - turn;
    }

    if (deq[0].size() > deq[1].size()) 
        cout << "do" << '\n';
    else if (deq[0].size() < deq[1].size())
        cout << "su" << '\n';
    else 
        cout << "dosu" << '\n';
    return 0;
}