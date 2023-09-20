#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    int n;
    map<char, int> m;
    int s = 0, e = 0, answer = 0;

    cin >> n;
    cin >> str;
    int len = str.size();
    while(s <= e && e < len){
        if(m.size() > n){
            if(m[str[s]] == 1) m.erase(str[s]);
            else m[str[s]]--;
            s++;
        } else {
            if(m.count(str[e]) == 0) m[str[e]] = 1;
            else m[str[e]]++;
            if(m.size() <= n) answer = max(answer, e-s+1);
            e++;
        }
    }
    cout << answer;
    return 0;
}
