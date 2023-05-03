#include <iostream>
#include <regex>
#include <string>

using namespace std;
int n;
string input;
regex pattern("(100+1+|01)+"); // 정규표현식

int main(){
    cin >> input;
    cout << (regex_match(input, pattern) ? "SUBMARINE" : "NOISE");    
    cout << '\n';
    return 0;
}