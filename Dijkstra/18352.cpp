#include <iostream>
#include <queue>

#define INF 987654321
using namespace std;
vector<pair<int, int> > map[300001];
vector<int> dist(300001, INF);
int n, m, k, x;

void dijkstra(int x){
    priority_queue<pair<int, int> > pq;
    dist[x] = 0;
    pq.push(make_pair(-dist[x], x));

    while(!pq.empty()){
        int cost = -pq.top().first;
        int now = pq.top().second;

        pq.pop();

        if(dist[now] < cost)
            continue;
        for(int i=0; i<map[now].size(); i++){
            int next = map[now][i].second;
            int viacost = map[now][i].first + cost;
            if(viacost < dist[next]){
                dist[next] = viacost;
                pq.push(make_pair(-viacost, next));
            }
        }
    }
}

int main(){
    cin >> n >> m >> k >> x;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        map[a].push_back(make_pair(1, b));
    }

    dijkstra(x);

    int flag = 0;
    for(int i=1; i<=n; i++){
        if(dist[i] == k){
            flag = 1;
            cout << i << '\n';
        }
    }
    if(!flag) cout << -1 << '\n';
    return 0;
}

