#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321
using namespace std;
int n, m, ts, te;
int dist[2501];
vector<pair<int, int> > v[2501];

void dijkstra(int start){
    dist[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(-dist[start], start));

    while(!pq.empty()){
        int nowval = -pq.top().first;
        int nowpos = pq.top().second;
        pq.pop();

        if(dist[nowpos] < nowval) continue;
        for(int i=0; i<v[nowpos].size(); i++){
            int nextpos = v[nowpos][i].second;
            int nextval = nowval + v[nowpos][i].first;

            if(nextval < dist[nextpos]){
                dist[nextpos] = nextval;
                pq.push(make_pair(-nextval, nextpos));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> ts >> te;
    fill(dist, dist+2501, INF);
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(c, b));
        v[b].push_back(make_pair(c, a));
    }
    for(int i=0; i<=n; i++){
        sort(v[i].begin(), v[i].end());
    }
    dijkstra(ts);
    cout << dist[te];
    return 0;
}
