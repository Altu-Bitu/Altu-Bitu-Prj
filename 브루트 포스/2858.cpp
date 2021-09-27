#include <iostream>

using namespace std;

int main(){
    int R, B, L, W;
    cin >> R >> B;
    
    int i = 0;
    while (++i){
        if (B % i == 0){
            int r = B / i;
            if ((r + i + 2) * 2 == R){
                L = r + 2;
                W = i + 2;
                cout << L << ' ' << W << endl;
                break;
            }
        }
        else 
            continue;
    }
    return 0;
}