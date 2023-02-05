#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 100000000
using namespace std;
vector<pair<int, int> > map[1001]; // map[a].push_back({b, c}) -> a도시에서 b도시까지의 거리는 c
vector<int> dist(1001, INF);

void dijkstra(int start){
    priority_queue<pair<int,int> > pq; // 거리, 노드 인덱스
    dist[start] = 0; // 시작 도시에서 시작 도시까지의 거리는 당연히 0
    pq.push(make_pair(dist[start], start)); // 시작 가중치 및 간선 번호 입력

    while(!pq.empty()){
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] < cost) // 이미 최단경로를 확인한 노드는 배제
            continue;

        for(int i=0; i<map[now].size(); i++){ // 현재 도시에서 다른 도시들로 향하는 경로의 개수만큼 순회
            int viacost = cost + map[now][i].second; // 현재 비용 + 현재도시 -> 다른도시 진입 비용
            if(viacost < dist[map[now][i].first]){
                dist[map[now][i].first] = viacost; // 최솟값 갱신
                pq.push(make_pair(-viacost, map[now][i].first)); // 우선순위 큐에 삽입
            }
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;

    while(M--){
        int s, e, val;
        cin >> s >> e >> val;
        map[s].push_back(make_pair(e, val));
    } // 입력

    int start, target; // 시작 도시와 도착 도시
    cin >> start >> target;

    dijkstra(start); // 시작 도시에서 다익스트라 알고리즘 개시

    cout << dist[target]; // 도착 도시까지의 최단 거리 출력
    return 0;
}