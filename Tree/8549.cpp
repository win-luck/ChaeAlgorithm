#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<pair<int, pair<int, int> > > v;
int parent[100001];

int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(v.begin(), v.end());
    int maxval = 0;
    for(int i=0; i<v.size(); i++){
        int s = v[i].second.first;
        int e = v[i].second.second;
        int val = v[i].first;
        if(find(s) != find(e)){
            merge(s, e);
            maxval = max(val, maxval);
        }
    }
    cout << maxval;
    return 0;
}
