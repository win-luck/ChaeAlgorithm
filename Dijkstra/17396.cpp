#include <iostream>
#include <queue>
#include <vector>

#define INF 10000000001 // c가 큰 편에 속하기에 INF값이 매우 커야 함
using namespace std;
int n, m;
int a, b, c;
vector<pair<int, int> > map[100001];
vector<long long> dist(100001, INF);
int isdark[100001];

long long dijkstra(int start){
    priority_queue<pair<long long, long long> > pq;
    dist[start] = 0;
    pq.push(make_pair(-dist[start], start));

    while(!pq.empty()){
        long long cost = -pq.top().first;
        long long now = pq.top().second;

        pq.pop();

        if(dist[now] < cost) // 이미 더 작은 경우 생략
            continue;

        for(int i=0; i<map[now].size(); i++){
            long long viacost = cost + map[now][i].first;
            long long next = map[now][i].second;

            if(viacost < dist[next] && (isdark[next] == 0 || next == n-1)){ // 갈 수 있는 곳이거나, 상대 넥서스거나
                dist[next] = viacost;
                pq.push(make_pair(-viacost, next));
            }
        }
    }
    return dist[n-1] >= INF ? -1 : dist[n-1]; // INF 이상이면 -1 반환
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> isdark[i];
    }
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        map[a].push_back(make_pair(c, b));
        map[b].push_back(make_pair(c, a)); // 그래프 방향 여부 항상 챙기자.
    }
    cout << dijkstra(0) << '\n';
    return 0;
}