#include <iostream>
#include <map>

using namespace std;
map<string, string> m;
int n;
string a, b;

int finds(string a, string b){
    while(1){
        if(a == b) return 1;
        if(m.find(a) == m.end()) return 0;
        a = m[a];
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        m[a] = b;
    }
    cin >> a >> b;
    if(finds(a, b) || finds(b, a)) cout << 1;
    else cout << 0;
    return 0;
}
