#include <iostream>
#include <queue>

using namespace std;
int n, m, from, to;
int arr[101][101];
int visited[101] = { 0, };

void BFS(int from){
    queue<int> q;
    q.push(from);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=1; i<=n; i++){
            if(arr[x][i] == 1 && !visited[i]){
                visited[i] = visited[x] + 1;
                q.push(i);
            }
        }
    }
}

int main(){
    cin >> n >> from >> to >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1; // 연결
    }
    BFS(from);

    if(visited[to] == 0){ // from에서 닿지 못함
        visited[to] = -1;
    }
    cout << visited[to];
    return 0;
}