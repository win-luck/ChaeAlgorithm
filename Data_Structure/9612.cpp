#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
map<string, int> m;

bool cmp(pair<string, int> p1, pair<string, int> p2){
    if(p1.second == p2.second){
        return p1.first > p2.first;
    }
    return p1.second > p2.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;

    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        m[str]++;
    }

    vector<pair<string, int> > v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    cout << v.front().first << " " << v.front().second;
    return 0;
}
