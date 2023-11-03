#include <iostream>
#include <map>

using namespace std;
map<string, int> m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    int n, a;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str >> a;
        if(m.count(str) == 0){
            m[str] = a;
        } else {
            m[str] += a;
        }
    }
    for(auto it: m){
        if(it.second == 5){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
