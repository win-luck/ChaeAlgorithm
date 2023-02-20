#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M, p, q, u, v;
long long w;
long long totalsum;
int parent[10001];

int Find(int num){
    if(num == parent[num])
        return num;
    return parent[num] = Find(parent[num]);
}

bool Union(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x == y) return false;
    else {
        parent[x] = y;
        return true;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--){
        cin >> N >> M >> p >> q;

        for(int i=1; i<=N; i++){
            parent[i] = i;
        }
        vector<pair<long long, pair<int, int> > > dist;
        bool flag = false;
        totalsum = 0; // 초기화

        for(int i=0; i<M; i++){
            cin >> u >> v >> w;
            dist.push_back(make_pair(w, make_pair(u, v)));
        }

        sort(dist.begin(), dist.end());
        for(int i=0; i < dist.size(); i++){
            int a = dist[i].second.first;
            int b = dist[i].second.second;

            if(Union(a, b)){
                totalsum += dist[i].first;
                if((a == p && b == q) || (a == q && b == p)){ // 만들어진 MST에 p, q가 포함되면 true
                    flag = true;
                }
            }
        }

        if(flag) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}