#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
int parent[100001];
int power[100001] = {0, };
int n, m, c, h, k;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    return p1.second > p2.second;
}

int find(int a){
    if(parent[a] == a){
        return a;
    }
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    power[a] += power[b];
    parent[b] = a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        parent[i] = i;
        power[i] = 1;
    }
    
    // 동맹 맺기
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        if(find(a) != find(b)){
            merge(a, b); 
        }
    }

    // 중립 동맹들의 정보 취합
    cin >> c >> h >> k;
    map<int, int> other;
    for(int i=1; i<=n; i++){
        if(find(i) != find(c) && find(i) != find(h)){
            other[find(i)] = power[find(i)]; 
        }
    }

    // 중립 동맹들 힘 내림차순 정렬하고, k번만큼 동맹 연결
    vector<pair<int, int> > v(other.begin(), other.end());
    sort(v.begin(), v.end(), cmp); 
    for(auto it: v){
        if(k == 0) break;
        power[find(c)] += it.second;
        k--;
    }
    cout << power[find(c)];
    return 0;
}
