#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
map<string, string> group;
map<string, vector<string> > member;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string g;
        int a;
        cin >> g >> a;
        for(int j=0; j<a; j++){
            string name;
            cin >> name;
            member[g].push_back(name);
            group[name] = g;
        }
        sort(member[g].begin(), member[g].end());
    }
    for(int i=1; i<=m; i++){
        string s;
        int type;
        cin >> s >> type;
        if(type == 0){
            for(auto it: member[s]){
                cout << it << '\n';
            }
        } else {
            cout << group[s] << '\n';
        }
    }
    return 0;
}
