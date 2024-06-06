#include <iostream>
#include <vector>

#define INF 987654321
struct edge {
    int x, y, val;
};
using namespace std;
int n, m;
long long dist[501];
vector<edge> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    for(int i=0; i<m; i++){
        edge e;
        cin >> e.x >> e.y >> e.val;
        v.push_back(e);
    }

    dist[1] = 0;
    for(int i=1; i<=n-1; i++){
        for(int j=0; j<v.size(); j++){
            int f = v[j].x;
            int t = v[j].y;
            int val = v[j].val;

            if(dist[f] == INF) continue;
            if(dist[t] > dist[f] + val){
                dist[t] = dist[f] + val;
            }
        }
    }

    for(int j=0; j<v.size(); j++){
        int f = v[j].x;
        int t = v[j].y;
        int val = v[j].val;

        if(dist[f] == INF) continue;
        if(dist[t] > dist[f] + val){
            cout << -1;
            return 0;
        }
    }

    for(int i=2; i<=n; i++){
        if(dist[i] == INF) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }
    return 0;
}
