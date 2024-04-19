#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
int a, b, g;
map<string, int> m;
string str;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt1=0, cnt2=0;

    cin >> a >> b >> g;
    for(int i=0; i<a; i++){
        cin >> str;
        m[str] = 1;
    }
    for(int i=0; i<a; i++){
        cin >> str;
        m[str] = 2;
    }
    for(int i=0; i<g; i++){
        cin >> str;
        if(m[str] == 1){
            cnt1++;
        } else {
            cnt2++;
        }
    }
    if(cnt1 == cnt2){
        cout << "TIE";
    } else if (cnt1 > cnt2){
        cout << "A";
    } else {
        cout << "B";
    }
    return 0;
}
