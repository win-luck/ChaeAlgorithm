#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    int cnt[4] = {13, 13, 13, 13};
    map<string, bool> m;

    cin >> str;
    for(int i=0; i<str.size(); i+=3){
        if(m.count(str.substr(i, 3)) > 0){
            cout << "GRESKA";
            return 0;
        }
        m[str.substr(i, 3)] = true;
    }
    for(auto it: m){
        if(it.first.front() == 'P'){
            cnt[0]--;
        } else if(it.first.front() == 'K'){
            cnt[1]--;
        } else if(it.first.front() == 'H'){
            cnt[2]--;
        } else {
            cnt[3]--;
        }
    }
    cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << " " << cnt[3];
    return 0;
}
