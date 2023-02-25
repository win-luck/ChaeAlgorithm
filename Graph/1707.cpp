#include <iostream>
#include <vector>
#include <cstring>

#define RED 1
#define BLUE 2
using namespace std;
int visited[20001]; // 이분 그래프 적용을 위한 배열
vector<int> graph[20001];
int v, e;

void DFS(int start){
    if(!visited[start]){
        visited[start] = RED;
    }

    int sz = graph[start].size();
    for(int i=0; i<sz; i++){
        int next = graph[start][i];
        if(!visited[next]){
            if(visited[start] == RED){ // 인접한 노드들은 반드시 다른 색이어야 한다.
                visited[next] = BLUE;
            } else if(visited[start] == BLUE){
                visited[next] = RED;
            }
            DFS(next);
        }
    }
}

bool isBinary(){
    for(int i=1; i<=v; i++){
        int sz = graph[i].size();
        for(int j=0; j<sz; j++){
            int next = graph[i][j];
            if(visited[next] == visited[i]){ // 인접한 노드가 같은 색이면 false
                return false;
            }
        }
    }
    return true;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> v >> e;
        for(int i=0; i<e; i++){
            int u, p;
            cin >> u >> p;
            graph[u].push_back(p);
            graph[p].push_back(u); // 항상 단방향/양방향 여부 판단하기
        }

        for(int i=1; i<=v; i++){ // DFS
            if(!visited[i]){
                DFS(i);
            }
        }

        if(isBinary()){ // 판정
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }

        memset(visited, 0, sizeof(visited)); // 다음을 위한 초기화
        for(int i=0; i<=v; i++){
            graph[i].clear();
        }
    }
    return 0;
}