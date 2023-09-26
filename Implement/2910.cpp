#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define ll long long
using namespace std;
map<ll, ll> m;
map<ll, ll> prior;
int n;
long long c;

bool cmp(pair<ll, ll> p1, pair<ll, ll> p2){
    // value desc
    // prior asc
    if(p1.second == p2.second){
        return prior[p1.first] < prior[p2.first];
    }
    return p1.second > p2.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> c;
    long long cnt = 1;
    for(int i=0; i<n; i++){
        ll a;
        cin >> a;
        if(m.count(a) == 0){
            prior[a] = cnt++;
        }
        m[a]++;
    }
    
    vector<pair<ll, ll> > answer(m.begin(), m.end());
    sort(answer.begin(), answer.end(), cmp);
    for(ll i=0; i<answer.size(); i++){
        for(ll j=0; j < answer[i].second; j++){
            cout << answer[i].first << " ";
        }
    }
    return 0;    
}
