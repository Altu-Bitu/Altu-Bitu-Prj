#include<iostream>
#include<string>

using namespace std;

string str;
bool cpp = false, java = false;

int main() {
    cin >> str;
    int size = str.length();

    //�� ó���� �빮���̸� error
    if (isupper(str[0])) {
        cout << "Error!" << endl;
        return 0;
    }

    for (int i = 0; i < size; i++) {
        //�빮�ڰ� ������ java
        if (isupper(str[i])) {
            java = true;
        }            

        //_�� ������ cpp
        if (str[i] == '_') {
            if (str[i + 1] == '_') {
                cout << "Error" << endl;
                return 0;
            }
            cpp = true;
        }
    }

    //java->cpp
    if (java) {
        for (int i = 0; i < size; ++i) {
            if (isupper(str[i]))
                cout << '_' << (char)(str[i] + 32);
            else
                cout << str[i];
        }
    }
    //java, cpp
    else if (!cpp)
        cout << str;
    //cpp->java
    else {
        for (int i = 0; i < size; ++i) {
            if (str[i] == '_')
                cout << (char)(str[++i] - 32);
            else
                cout << str[i];
        }
    }
}