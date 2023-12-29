#include <iostream>

using namespace std;
string str;

int main(){
    cin >> str;
    long long sum = 0;
    for(int i=0; i<str.size(); i++){
        int a = str[i] - '0';
        sum += a*a*a*a*a;
    }
    cout << sum;
    return 0;
}
