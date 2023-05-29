#include <iostream>
#include <map>

using namespace std;
int n;
int cnt = 0;
map<string, bool> m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    m["ChongChong"] = true;
    cnt++;
    for(int i=0; i<n; i++){
        string str1, str2;
        cin >> str1 >> str2;
        if(m[str1] == true && m[str2] == false) {
            m[str2] = true;
            cnt++;
        }
        if(m[str1] == false && m[str2] == true) {
            m[str1] = true;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}