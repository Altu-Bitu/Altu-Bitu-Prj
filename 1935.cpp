#include <iostream>
#include <string>
#include <stack>

using namespace std;

int a[26];

int main(void)
{
    int N;
    string exp;
    stack<double> s;

    cin >> N;    
    cin >> exp;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }   

    for (int i = 0; i < exp.length(); i++){
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*'){
            double a = s.top();
            s.pop();

            double b = s.top();
            s.pop();

            switch (exp[i]){
            case '+':
                s.push(b + a);
                break;
            case '-':
                s.push(b - a);
                break;
            case '/':
                s.push(b / a);
                break;
            case '*':
                s.push(b * a);
                break;
            }
        }
        else {
            s.push(a[exp[i] - 'A']);
        }
    }

    double result = s.top();

    cout << fixed;
    cout.precision(2);
    cout << result;

    return 0;
}