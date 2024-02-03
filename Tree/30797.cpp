#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

int n, q;
ll parent[200001];
vector<pair<pair<ll, ll>, pair<ll, ll> > > edge;

ll find(ll num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

bool allconnected(){
    for(int i=2; i<=n; i++){
        if(find(1) != find(i)) return false;
    }
    return true;
}

bool cmp(pair<pair<ll, ll>, pair<ll, ll> > p1, pair<pair<ll, ll>, pair<ll, ll> > p2){
    if(p1.first.first == p2.first.first) return p1.first.second < p2.first.second;
    return p1.first.first < p2.first.first;
}

void merge(ll a, ll b){
    a = find(a);
    b = find(b);
    parent[b] = a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i=0; i<=200000; i++){
        parent[i] = i;
    }

    cin >> n >> q;
    for(int i=0; i<q; i++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a > b) swap(a, b);
        edge.push_back(make_pair(make_pair(c, d), make_pair(a, b)));
    }

    sort(edge.begin(), edge.end(), cmp);
    ll cnt = 0;
    ll lasttime = 0;
    for(int i=0; i<edge.size(); i++){
        ll val = edge[i].first.first;
        ll time = edge[i].first.second;
        ll a = edge[i].second.first;
        ll b = edge[i].second.second;

        if(find(a) != find(b)){
            merge(a, b);
            cnt += val;
            lasttime = max(lasttime, time);
        }
    }
    if(allconnected()){
        cout << lasttime << " " << cnt;
    } else {
        cout << -1;
    }
    return 0;
}
