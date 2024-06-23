#include <iostream>
#include <map>
#include <vector>

using namespace std;
int n;
map<string, vector<string> > m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        string p, s;
        cin >> p >> s;
        m[s].push_back(p);
    }

    vector<pair<string, string> > answer;
    for(auto it: m){
        if(it.first != "-" && it.second.size() == 2){
            vector<string> now = it.second;
            answer.push_back(make_pair(now[0], now[1]));
        }
    }
    cout << answer.size() << '\n';
    for(auto it: answer){
        cout << it.first << " " << it.second << '\n';
    }
    return 0;
}
