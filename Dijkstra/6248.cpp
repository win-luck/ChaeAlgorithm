#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;
int n, m, x;
int result = 0;
vector<pair<int, int> > v[1001];
int dist[1001];

void dijkstra(int a){
    dist[a] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(-dist[a], a));

    while(!pq.empty()){
        int val = -pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        if(val > dist[pos]) continue;

        for(int i=0; i<v[pos].size(); i++){
            int newpos = v[pos][i].second;
            int newval = val + v[pos][i].first;

            if(newval < dist[newpos]){
                dist[newpos] = newval;
                pq.push(make_pair(-newval, newpos));
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(i == x || dist[i] == INF) continue;
        result = max(result, dist[i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x;
    fill(dist, dist+1001, INF);
    for(int i=0; i<m; i++){
        int a, b, t;
        cin >> a >> b >> t;
        v[a].push_back(make_pair(t, b));
        v[b].push_back(make_pair(t, a));
    }
    for(int i=0; i<=n; i++){
        sort(v[i].begin(), v[i].end());
    }
    dijkstra(x);
    cout << result*2;
    return 0;
}
