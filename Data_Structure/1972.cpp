#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
string input;

bool check(string a, int n){
    map<string, bool> m;
    for(int i=0; i<a.size()-n-1; i++){
        string tmp = "";
        tmp += a[i];
        tmp += a[i+n+1]; // 문제 이해를 제대로 못했다.
        if(m[tmp] == true){ // 존재하는지 확인
            return false;
        } else {
            m[tmp] = true;
        }
    }
    return true;
}

bool validcheck(string a){
    if(a.size() == 1) return true; // 1개면 무조건 성공
    for(int i=0; i<=a.size()-2; i++){ // 적어도 2개만큼은 적어야함
        if(!check(a, i)) return false;
    }
    return true;
}


int main(){
    while(1) {
        cin >> input;
        if(input == "*") break;
        if(validcheck(input)){
            cout << input << " is surprising." << '\n';
        } else {
            cout << input << " is NOT surprising." << '\n';
        }
    }
    return 0;
}