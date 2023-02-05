#include <iostream>
#include <vector>
#include <queue>

#define INF 100000000
using namespace std;
int result, times, T, n, d, c;

void dijkstra(int start, vector<pair<int, int> > map[]){
    vector<int> dist(n+1, INF); // 거리, 최초엔 INF로 초기화한다.
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

    result = 0;
    times = 0;   
    for(int i=1; i<=n; i++){
        times += (dist[i] >= INF ? 0 : 1); // INF보다 작으면 감염에 성공시킨 컴퓨터이므로 하나씩 추가
        result = max((dist[i] >= INF ? -1 : dist[i]), result); // 감염시킨 컴퓨터 중 가장 긴 거리가 정답이다.
    }
}

int main(){
    cin >> T;
    for(int i=0; i<T; i++){
        vector<pair<int, int> > map[10001];
        cin >> n >> d >> c;
        for(int i=0; i<d; i++){
            int a, b, s;
            cin >> a >> b >> s;
            map[b].push_back(make_pair(a, s)); // a번 컴퓨터가 b번을 전염시키는데 s초가 소요된다.
        } // 입력

        dijkstra(c, map); // 이번 테스트케이스 map의 감염 시작점은 c
        cout << times << " " << result << endl;
    }
    return 0;
}