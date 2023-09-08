#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define INF 987654321
using namespace std;
vector<pair<int, int> > edge[101];
int d[101];
int n, e, t, m;

void dijkstra(int start){
    priority_queue<pair<int, int> > pq;
    d[start] = 0;
    pq.push(make_pair(-d[start], start));

    while(!pq.empty()){
        int nowdist = -pq.top().first;
        int now = pq.top().second;

        pq.pop();

        if(nowdist > d[now]) continue;
        
        for(int i=0; i<edge[now].size(); i++){
            int next = edge[now][i].first;
            int nextdist = nowdist + edge[now][i].second;

            if(d[next] > nextdist){
                d[next] = nextdist;
                pq.push(make_pair(-nextdist, next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> e;
    cin >> t;
    cin >> m;
    for(int i=0; i<=n; i++) d[i] = INF;
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[b].push_back(make_pair(a, c));
    }
    dijkstra(e);

    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(d[i] <= t){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
