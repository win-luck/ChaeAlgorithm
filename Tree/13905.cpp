#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int parent[100001];
vector<pair<int, pair<int, int> > > v;
int n, m, s, e;

bool cmp(pair<int, pair<int, int> > v1, pair<int, pair<int, int> > v2){
    return v1.first > v2.first;
} // 무게제한 내림차순

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
    cin >> s >> e;
    for(int i=0; i<=n; i++){
        parent[i] = i;
    }

    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_pair(c, make_pair(a, b)));
        v.push_back(make_pair(c, make_pair(b, a)));
    }

    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++){
        int a = v[i].second.first;
        int b = v[i].second.second;
        int val = v[i].first;

        if(find(a) != find(b)){
            merge(a, b);
        }

        if(find(s) == find(e)){ // 도착
            cout << val << '\n'; // 마지막으로 놓은 간선이 정답이 된다.
            return 0;
        }
    }
    cout << 0 << '\n'; // 도착할 수 없음
    return 0;
}