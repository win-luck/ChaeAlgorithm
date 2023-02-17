#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, t;
int result = 0;
bool visited[10001];
vector<vector<pair<int, int> > > edges; // 다음 노드, 비용
priority_queue<pair<int, int> > pq; // 비용, 다음 노드


void prim(int pos, int cnt){ // prim 알고리즘 적용 (왜? 간선 기준이 아닌 노드 기준으로 탐색하므로) 
    visited[pos] = true;

    for(int i=0; i<edges[pos].size(); i++){
        int nextpos = edges[pos][i].first;
        int cost = edges[pos][i].second;

        if(!visited[nextpos]) pq.push(make_pair(-cost, nextpos));
    }

    while(!pq.empty()){
        int nextpos = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(visited[nextpos]) continue;
        result += cost + cnt*t;
        prim(nextpos, cnt+1);
        return;
    }
}

int main(){
    cin >> N >> M >> t;
    int a, b, c;
    edges.resize(N+1); // 공간 할당
    
    for(int i=0; i<M; i++){
        cin >> a >> b >> c; // 양방향
        edges[a].push_back(make_pair(b, c)); // a에서 b로 가는 데 c원
        edges[b].push_back(make_pair(a, c));
    }

    prim(1, 0); // 특정 노드 기준으로 트리가 생성되므로 Prim 알고리즘
    cout << result << endl;
    return 0;
}