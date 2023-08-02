#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
int s;
int parent[2001];
vector<pair<int, pair<int, int> > > v;

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

    cin >> n >> m >> s;
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_pair(c, make_pair(a, b)));
        v.push_back(make_pair(c, make_pair(b, a)));
    } // 간선 입력

    sort(v.begin(), v.end());
    int res = 0;
    for(int i=0; i<v.size(); i++){
        int a = v[i].second.first;
        int b = v[i].second.second;

        if(find(a) != find(b)){
            merge(a, b);
            res += v[i].first;
        }
    }
    cout << res << '\n';
    return 0;
}