#include <iostream>
#include <regex>
#include <string>

using namespace std;
int n;
string input;
regex pattern("(100+1+|01)+"); // 정규표현식

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> input;
        cout << (regex_match(input, pattern) ? "YES" : "NO");
        cout << '\n';
    }
    return 0;
}