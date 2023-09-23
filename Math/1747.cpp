#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int n){
    if(n == 1) return false;
    if(n == 2) return true;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0) return false;
    }
    return true;
}

bool isPalind(string str){
    string now = str;
    reverse(str.begin(), str.end());
    for(int i=0; i<str.size(); i++){
        if(str[i] != now[i]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int answer = 0;

    cin >> n;
    for(int i=n; ; i++){
        if(isPrime(i)){
            if(isPalind(to_string(i))){
                answer = i;
                break;
            }
        }
    }
    cout << answer;
    return 0;
}