#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m;
int map[251][251];
bool visited[251][251];
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

void DFS(int x, int y){
    visited[x][y] = true;

    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny]) continue;
        if(map[nx][ny] == 1){
            DFS(nx, ny);
        }
    }
}

int main(){
    cin >> n >> m;
    memset(visited, false, sizeof(visited));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 1 && !visited[i][j]){
                DFS(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
