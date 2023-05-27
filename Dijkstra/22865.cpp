#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX 100001
#define INF 1e9

using namespace std;
int n, m;
int Cost[3][MAX]; // 3명의 친구가 각 노드로 향하는 비용
int f[3]; // 3명의 친구
int res = -1, id = 0;
vector<pair<int, int> > Edges[MAX];

void input(){
    cin >> n;
    for(int i=0; i<3; i++){
        for(int j=1; j<=n; j++){
            Cost[i][j] = INF;
        }
    }
    for(int i=0; i<3; i++){
        cin >> f[i];
    }
    cin >> m;
    for(int i=0; i<m; i++){
        int d, e, l;
        cin >> d >> e >> l;
        Edges[d].push_back(make_pair(e, l)); // 양방향
        Edges[e].push_back(make_pair(d, l));
    }
}

void dijkstra(int X, int v){
    priority_queue<pair<int, int> > pq;
    Cost[X][v] = 0; // i번째 친구의 자기 자신으로 향하는 비용은 0
    pq.push(make_pair(0, v)); // 최초 자기 자신에서 시작할 때는 비용이 0

    while(!pq.empty()){
        int nowcost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(Cost[X][now] < nowcost)
            continue;

        
        for(int i=0; i < Edges[now].size(); i++){
            int nextcost = Edges[now][i].second;
            int next = Edges[now][i].first;

            if(Cost[X][next] > nowcost + nextcost){
                Cost[X][next] = nowcost + nextcost;
                pq.push(make_pair(-Cost[X][next], next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    for(int i=0; i<3; i++){
        dijkstra(i, f[i]); // i-1번째 친구의 다익스트라
    }
    for(int i=1; i<=n; i++){
        if((f[0] == i) || (f[1] == i) || (f[2] == i)) // 친구가 자기 자신의 집으로 향하는 거리는 배제 (무조건 0이니까)
            continue;
        int temp = min(Cost[0][i], min(Cost[1][i], Cost[2][i])); // 세 친구의 각각 i노드로 향하는 거리 중 가장 먼 것
        if(res < temp){ // 이 갱신될 수 있다면 그 노드의 인덱스가 정답
            res = temp;
            id = i;
        }
    }
    cout << id << '\n';
    return 0;
}