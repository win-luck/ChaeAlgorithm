#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string s, t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    cin >> t;
    string t1 = "";
    string t2 = "";

    for(int i=0; i<s.size(); i++){
        t1 += t;
    }
    for(int i=0; i<t.size(); i++){
        t2 += s;
    }
    cout << ((t1 == t2) ? 1 : 0);
    return 0;
}
