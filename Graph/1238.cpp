#include <iostream>
#include <vector>
#include <queue>

#define INF 100000000
using namespace std;
vector<pair<int, int> > map[10001]; // map[a].push_back({b, c}) -> a도시에서 b도시까지의 거리는 c
int result, N, M, X;

int dijkstra(int start, int end){ // 최소 비용 -> 다익스트라 or 플로이드 or 최소스패닝트리
    vector<int> dist(N+1, INF); // 거리, 최초엔 INF로 초기화한다.
    priority_queue<pair<int, int> > pq; // 우선순위 큐를 활용한 다익스트라
    
    dist[start] = 0; // 시작 도시에서 시작 도시까지의 거리는 당연히 0
    pq.push(make_pair(dist[start], start)); // 시작 가중치 및 간선 번호 입력

    while(pq.size()){
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(cost < dist[now])
            continue;

        for(int i=0; i<map[now].size(); i++){ // 현재 도시에서 다른 도시들로 향하는 경로의 개수만큼 순회
            int viacost = cost + map[now][i].second; // 현재 비용 + 현재도시 -> 다른도시 진입 비용
            int next = map[now][i].first;
            
            if(viacost < dist[next]){
                dist[next] = viacost; // 최솟값 갱신
                pq.push(make_pair(-viacost, next)); // 우선순위 큐에 삽입
            }
        }
    }

    return dist[end];
}

int main(){
    cin >> N >> M >> X;

    for(int i=0; i<M; i++){
        int s, e, val;
        cin >> s >> e >> val;
        map[s].push_back(make_pair(e, val));
    } // 입력

    int result = -1;
    for(int i=1; i<=N; i++){ // 1번 학생부터 N번 학생들 중 왕복이 가장 오래걸리는 학생의 왕복 시간
        result = max(result, dijkstra(i, X) + dijkstra(X, i));
    }

    cout << result << endl;
    return 0;
}