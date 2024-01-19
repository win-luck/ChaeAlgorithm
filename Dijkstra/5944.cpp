#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;
int n, m, s, t1, t2;
vector<pair<int, int> > v[200001];
long long dist[200001];

void dijkstra(int start){
    dist[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(-dist[start], start));

    while(!pq.empty()){
        int val = -pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        if(dist[pos] < val) continue;

        for(int i=0; i<v[pos].size(); i++){
            int nextval = val + v[pos][i].second;
            int nextpos = v[pos][i].first;

            if(dist[nextpos] > nextval){
                dist[nextpos] = nextval;
                pq.push(make_pair(-nextval, nextpos));
            }
        }
    }
}

long long movepath(int s, int t1, int t2){
    long long sum = 0;
    dijkstra(s);
    sum += dist[t1];
    fill(dist, dist+200001, INF);
    dijkstra(t1);
    sum += dist[t2];
    fill(dist, dist+200001, INF);
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s >> t1 >> t2;
    for(int i=1; i<=n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    fill(dist, dist+200001, INF);
    cout << min(movepath(s, t1, t2), movepath(s, t2, t1));
    return 0;
}
