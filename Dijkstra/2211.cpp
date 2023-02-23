#include <iostream>
#include <queue>

#define INF 987654321
using namespace std;
int n, m, a, b, c;
vector<pair<int, int> > map[1001];
int parent[1001];

void dijkstra(){
    vector<int> dist(n+1, INF); // 거리, 최초엔 INF로 초기화한다.
    priority_queue<pair<int, int> > pq; // 거리, 시작점으로부터의

    dist[1] = 0;
    pq.push(make_pair(dist[1], 1)); // 비용, 노드 번호
    parent[1] = 1;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        for(int i=0; i<map[now].size(); i++){
            int viacost = cost + map[now][i].second;
            int next = map[now][i].first;

            if(viacost < dist[next]){
                dist[next] = viacost;
                pq.push(make_pair(-viacost, next));
                parent[next] = now; // 간선의 부모 저장
            }
        }
    }
}

int main(){
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
        map[b].push_back(make_pair(a, c));
    }

    dijkstra();
    cout << n-1 << '\n'; // 1번 조건의 결론: n-1개의 간선이 필요하다.
    for(int i=2; i<=n; i++){ // n-1개의 실제 간선을 보여주면 된다. MST와 유사한 문제.
        cout << i << " " << parent[i] << '\n';
    }
    return 0;
}