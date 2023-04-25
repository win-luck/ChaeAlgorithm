#include <iostream>

using namespace std;
int T, a, b;
string str;


int main(){
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> str;
        int sum = (str[0] - '0') + (str[2] - '0');
        cout << sum << '\n';
    }
    return 0;
}