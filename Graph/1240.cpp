#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n, m;
vector<pair<int, int> > node[1001];
bool visited[1001];

void DFS(int u, int v, int len){
    if(u == v){ // 도착
        cout << len << '\n';
        return;
    }
    visited[u] = true;

    for(int i=0; i<node[u].size(); i++){
        int next = node[u][i].first; // 다음 노드
        int l = node[u][i].second; // 까지의 거리

        if(visited[next]) continue;

        visited[next] = true;
        DFS(next, v, len + l);
        visited[next] = false;
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n-1; i++){
        int a, b, c;
        cin >> a >> b >> c; // a노드와 b노드의 거리는 c
        node[a].push_back(make_pair(b, c));
        node[b].push_back(make_pair(a, c));
    }

    for(int i=0; i<m; i++){ // DFS 개시
        memset(visited, false, sizeof(visited));
        int u, v;
        cin >> u >> v;
        DFS(u, v, 0);
    }
    return 0;
}