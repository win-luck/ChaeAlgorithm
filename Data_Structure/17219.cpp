#include <iostream>
#include <map>

using namespace std;
int n, m;
string name, pw;
map<string, string> memo; // key-value 형태의 자료구조는 map

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> name;
        cin >> pw;
        memo[name] = pw;
    }

    for(int i=0; i<m; i++){
        cin >> name;
        cout << memo[name] << '\n';
    }
    return 0;
}