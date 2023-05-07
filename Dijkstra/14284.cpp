#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321
using namespace std;
int n, m;
int a, b, c;
int start, finish;
vector<pair<int, int> > map[5001];
vector<int> dist(5001, INF);

long long dijkstra(int start){ // 일반적인 우선순위큐 다익스트라 알고리즘
    priority_queue<pair<int, int> > pq;
    dist[start] = 0;
    pq.push(make_pair(-dist[start], start));

    while(!pq.empty()){
        int cost = -pq.top().first;
        int now = pq.top().second;

        pq.pop();

        if(dist[now] < cost) // 이미 더 작은 경우 생략
            continue;

        for(int i=0; i<map[now].size(); i++){
            int viacost = cost + map[now][i].first;
            int next = map[now][i].second;

            if(viacost < dist[next]){
                dist[next] = viacost;
                pq.push(make_pair(-viacost, next));
            }
        }
    }
    return dist[finish];
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        map[a].push_back(make_pair(c, b));
        map[b].push_back(make_pair(c, a)); // 그래프 방향 여부 항상 챙기자.
    }

    cin >> start >> finish;
    cout << dijkstra(start) << '\n';
    return 0;
}