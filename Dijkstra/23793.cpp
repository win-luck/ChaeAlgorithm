#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 10e9
using namespace std;
long long n, m, x, y, z;
vector<pair<long long, long long> > edge[100001];
long long dist[100001];

long long dijkstra(int start, int end, bool flag){
    fill(dist, dist+100001, INF);
    priority_queue<pair<long long, long long> > pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while(!pq.empty()){
        long long nowval = -pq.top().first;
        long long nowpos = pq.top().second;
        pq.pop();

        if(dist[nowpos] < nowval) continue;

        for(int i=0; i<edge[nowpos].size(); i++){
            if(flag && edge[nowpos][i].second == y) continue;
            long long nextpos = edge[nowpos][i].second;
            long long nextval = nowval + edge[nowpos][i].first;

            if(nextval < dist[nextpos]){
                dist[nextpos] = nextval;
                pq.push(make_pair(-nextval, nextpos));
            }
        }
    }
    return dist[end];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back(make_pair(w, v)); // 단방향
    }
    
    cin >> x >> y >> z;
    long long a = dijkstra(x, y, false);
    long long b = dijkstra(y, z, false);
    if(a == INF || b == INF) cout << -1 << " ";
    else cout << (a + b) << " ";

    long long c = dijkstra(x, z, true);
    if(c == INF) cout << -1;
    else cout << c;
    return 0;
}
