#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int t, n, m;
long long res = 0;
long long total = 0;
int parent[100001];
vector<pair<long long, pair<int, int> > > v;

int find(int num){
    if(num == parent[num])
        return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    parent[a] = b;
} // 유니온파인드

void build(){
    sort(v.begin(), v.end()); // 정렬하고 MST 형성
    for(int i=0; i<v.size(); i++){
        int s = v[i].second.first;
        int e = v[i].second.second;
        long long val = v[i].first;

        if(find(s) != find(e)){
            merge(s, e);
            res += val;
        }
    }
    total ^= res; // XOR 연산
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for(int a=0; a<t; a++){
        v.clear();
        total = 0;
        cin >> n >> m;
        for(int i=1; i<=n-1; i++){
            int a;
            long long b;
            cin >> a >> b;
            v.push_back(make_pair(b, make_pair(i, a)));
        }

        for(int i=1; i<=m; i++){
            for(int j=0; j<=n; j++){ // 한 줄씩 추가될때마다 아예 새로 MST를 구축하는 비용들을 새로 계산함
                parent[j] = j;
            }
            res = 0;

            int a, b;
            long long c;
            cin >> a >> b >> c;
            v.push_back(make_pair(c, make_pair(a, b)));
            build();
        }
        cout << total << '\n';
    }
    return 0;
}