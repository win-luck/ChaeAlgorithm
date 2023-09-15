#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

#define INF 9876543210000
using namespace std;
long long n, m, k;
long long d[100001];
long long target[100001];
long long answer[100001];
vector<pair<long long, long long> > edge[100001];

void dijkstra(){

    priority_queue<pair<long long, long long> > pq;
    for(int i=1; i<=k; i++){
        d[target[i]] = 0;
        pq.push(make_pair(0, target[i]));
    }

    while(!pq.empty()){
        long long nowdist = -pq.top().first;
        long long now = pq.top().second;

        pq.pop();

        if(nowdist > d[now]) continue;
        
        for(int i=0; i<edge[now].size(); i++){
            long long next = edge[now][i].first;
            long long nextdist = nowdist + edge[now][i].second;

            if(d[next] > nextdist){
                d[next] = nextdist;
                pq.push(make_pair(-nextdist, next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[b].push_back(make_pair(a, c));
    }

    for(int i=1; i<=k; i++){
        cin >> target[i];
    }

    fill(d, d + 100001, INF);
    dijkstra();

    int idx;
    long long ans = 0;
    for(int i=1; i<=n; i++){
        if(d[i] > ans){
            ans = d[i];
            idx = i;
        }
    }
    cout << idx << '\n' << ans << '\n';
    return 0;
}
