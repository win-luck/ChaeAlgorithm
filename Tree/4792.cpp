#include <iostream>
#include <vector>
#include <algorithm>

#define pi pair<char, pair<int, int> >
using namespace std;
int parent[1001];
int n, m, k;
vector<pi> v;

int Find(int num){
    if(num == parent[num])
        return num;
    return parent[num] = Find(parent[num]);
}

bool Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a == b) return false;
    else {
        parent[a] = b;
        return true;
    }
}

bool REDfirst(pi a, pi b){
    return a.first > b.first;
}

bool BLUEfirst(pi a, pi b){
    return a.first < b.first;
}

int MST(int n){
    int cnt = 0;
    for(int i=1; i<=n; i++) 
        parent[i] = i;

    for(int i=0; i<v.size(); i++){
        int a = v[i].second.first;
        int b = v[i].second.second;
        if(Union(a, b)){
            if(v[i].first == 'B') cnt++; // 블루에만 가중치를 준다고 생각하면 된다.
        }
    }
    return cnt;
}

int main(){
    while(1){
        cin >> n >> m >> k;
        if(n == 0 && m == 0 && k == 0) break;

        int f, t;
        char c;
        for(int i=0; i<m; i++){
            cin >> c;
            cin >> f >> t;
            v.push_back(make_pair(c, make_pair(f, t)));
        }

        sort(v.begin(), v.end(), REDfirst); // 빨간 간선 먼저 조합하기
        int range1 = MST(n); // 당연히 파랑간선이 최소

        sort(v.begin(), v.end(), BLUEfirst); // 파랑 간선 먼저 조합하기
        int range2 = MST(n); // 당연히 파랑간선이 최대

        if(k >= range1 && k <= range2){ // 범위 내에 있으면 1
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }

        v.clear();
    }

    return 0;
}