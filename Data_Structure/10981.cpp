#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
struct team {
    string name;
    int cnt, penalty;
    team(string a, int b, int c){
        name = a;
        cnt = b;
        penalty = c;
    }
};
int n, k;
map<string, vector<team> > univ;

bool cmp(team t1, team t2){
    if(t1.cnt == t2.cnt){
        return t1.penalty < t2.penalty;
    }
    return t1.cnt > t2.cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++){
        string u, name;
        int cnt, p;
        cin >> u >> name >> cnt >> p;
        univ[u].push_back(team(name, cnt, p));
    }
    vector<team> best;
    for(auto it: univ){
        vector<team> now = it.second;
        sort(now.begin(), now.end(), cmp);
        best.push_back(now[0]);
    }
    
    sort(best.begin(), best.end(), cmp);
    for(int i=0; i<k; i++){
        cout << best[i].name << '\n';
    }
    return 0;
}
