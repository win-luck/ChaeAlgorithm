#include <iostream>
#include <algorithm>

using namespace std;
bool flag;
string s, e;

void recur(string str){
    if(flag) return;
    if(str.size() < s.size()) return;
    if(str == s){
        cout << 1 << '\n';
        exit(0);
    }

    if(str.back() == 'A'){
        string tmp = str;
        tmp.pop_back();
        recur(tmp);
    } 
    
    if(str.front() == 'B'){
        string tmp = str;
        reverse(tmp.begin(), tmp.end());
        tmp.pop_back();
        recur(tmp);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    cin >> e;
    recur(e);
    cout << 0 << '\n';
    return 0;
}