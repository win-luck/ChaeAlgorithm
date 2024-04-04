#include <iostream>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    string str;

    cin >> t;
    for(int i=0; i<t; i++){
        set<string> s;
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> str;
            s.insert(str);
        }
        cout << s.size() << '\n';
    }
    return 0;
}
