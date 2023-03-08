#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int visited[2001];
int n, m, a, b, flag;
vector<int> v[2001];

void DFS(int depth, int now){
    if(depth == 4){ // 5친구가 존재함이 입증됨 (백트래킹)
        flag = true;
        return;
    }

    for(int i=0; i<v[now].size(); i++){ // DFS 방식으로 노드 방문
        if(visited[v[now][i]]) continue;
        visited[v[now][i]] = true;
        DFS(depth + 1, v[now][i]);
        visited[v[now][i]] = false;
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=0; i<n; i++){
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        DFS(0, i);
        if(flag) break;
    }

    cout << flag << '\n';
    return 0;
}