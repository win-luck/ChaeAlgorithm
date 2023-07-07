#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int p, r;
int parent[51];
vector<pair<int, pair<int, int> > > v; // 가중치, 출발점, 도착점

int find(int num){ // kruskal
    if(num == parent[num]){
        return num;
    }
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

    while(1){
        cin >> p;
        if(p == 0) break;
        cin >> r;
        int answer = 0;
        for(int i=0; i<=p; i++){
            parent[i] = i;
        }
        v.clear(); // 케이스마다 초기화

        for(int i=0; i<r; i++){
            int a, b, c;
            cin >> a >> b >> c;
            v.push_back(make_pair(c, make_pair(a, b)));
        }

        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++){
            int s = v[i].second.first;
            int e = v[i].second.second;

            if(find(s) != find(e)){
                merge(s, e);
                answer += v[i].first;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}