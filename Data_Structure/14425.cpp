#include <iostream>
#include <map>

using namespace std;
int n, m;
int cnt = 0;
string s;
map<string, bool> v;

int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> s;
        v[s] = true;
    }

    for(int i=0; i<m; i++){
        cin >> s;
        if(v[s]) cnt++;
    }
    
    cout << cnt;
    return 0;
}