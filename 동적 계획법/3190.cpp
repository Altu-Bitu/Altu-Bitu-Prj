#include <iostream> 
#include <queue>
#define MAX 100 + 1

using namespace std;

enum {
    UP, RIGHT, DOWN, LEFT
};

int board[MAX][MAX] = { 0 };
int x[4] = { -1, 0 , 1, 0 };
int y[4] = { 0, 1, 0, -1 };
int dir = RIGHT;
int N, time = 0;
deque<pair<int, int>> snake;

void changeDir(char way) {
    if (way == 'L') {
        dir = (dir + 3) % 4;
        return;
    }
    if (way == 'D') {
        dir = (dir + 1) % 4;
        return;
    }
}

bool move() {
    pair<int, int> before_top = snake.front();
    int preX = before_top.first + x[dir];
    int preY = before_top.second + y[dir];

    if (preX < 1 || preX > N || preY < 1 || preY > N) 
        return false;
    if (board[preX][preY] == -1) 
        return false;

    snake.push_front({ preX, preY });

    if (board[preX][preY] != 1) {
        board[snake.back().first][snake.back().second] = 0;
        snake.pop_back();
    }
    board[preX][preY] = -1;
    return true;
}

int main() {
    snake.push_back({ 1,1 }); 
    board[1][1] = -1;
    int K; 
    cin >> N >> K;

    for (int K_idx = 0; K_idx < K; K_idx++) {
        int row, col; 
        cin >> row >> col;
        board[row][col] = 1;
    }

    int L; 
    cin >> L;
    for (int L_idx = 0; L_idx < L; L_idx++) {
        int X;
        char C; 
        cin >> X >> C;
        while (time != X) {
            if (move() == false) {
                cout << time + 1;
                return 0;
            }
            time++;
        }
        changeDir(C);
    }

    while (1) {
        if (move() == false) {
            cout << time + 1;
            return 0;
        }
        time++;
    }
    return 0;
}
