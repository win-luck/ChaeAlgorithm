#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int cnt[26] = {0,};
        bool flag = true;
        for(int i=0; i<s.size(); i++){
            cnt[s[i]-'A']++;
            if(cnt[s[i]-'A'] == 3){
                if(i+1 == s.size() || s[i] != s[i+1]){
                    flag = false;
                    break;
                }
                cnt[s[i]-'A'] = 0;
                i++;
            }
        }
        if(flag) cout << "OK\n";
        else cout << "FAKE\n";
    }
    return 0;
}
