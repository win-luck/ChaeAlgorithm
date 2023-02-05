#include <iostream>
#include <vector>
#include <queue>

#define INF 10e8
using namespace std;
vector<pair<int, int> > map[801]; // map[a].push_back({b, c}) -> a도시에서 b도시까지의 거리는 c
int result, N, M;
bool flag = true;

int dijkstra(int start, int end){ // 최소 비용 -> 다익스트라 or 플로이드 or 최소스패닝트리
    vector<int> dist(N+1, INF); // 거리, 최초엔 INF로 초기화한다.
    priority_queue<pair<int, int> > pq; // 우선순위 큐를 활용한 다익스트라
    
    dist[start] = 0; // 시작 도시에서 시작 도시까지의 거리는 당연히 0
    pq.push(make_pair(dist[start], start)); // 시작 가중치 및 간선 번호 입력

    while(pq.size()){
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(now == end) // 정상적으로 최단 거리를 형성하며 도착
            return cost;

        for(int i=0; i<map[now].size(); i++){ // 현재 도시에서 다른 도시들로 향하는 경로의 개수만큼 순회
            int viacost = cost + map[now][i].second; // 현재 비용 + 현재도시 -> 다른도시 진입 비용
            int next = map[now][i].first;
            
            if(viacost < dist[next]){
                dist[next] = viacost; // 최솟값 갱신
                pq.push(make_pair(-viacost, next)); // 우선순위 큐에 삽입
            }
        }
    }
    flag = false; // while문 이탈 -> 최단거리 형성 실패
    return 0;
}

int main(){
    cin >> N >> M;

    for(int i=0; i<M; i++){
        int s, e, val;
        cin >> s >> e >> val;
        map[s].push_back(make_pair(e, val));
        map[e].push_back(make_pair(s, val)); // "양방향" 이란 부분을 놓쳤다. 다음에 다시 풀어보자.
    } // 입력

    int v1, v2, num1, num2; // 반드시 거쳐야 하는 두 정점
    cin >> v1 >> v2;
    num1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
    num2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);
    // 출발점 -> v1 -> v2 -> 도착점 vs 출발점 -> v2 -> v1 -> 도착점 중 작은 것이 정답이다.
    result = min(num1, num2);
    if(flag){
        cout << result << endl;
    } else {
        cout << -1 << endl;
    }
}