#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n, m;
int map[301][301];
bool visited[301][301] = {false, };
int dx[2] = {1, 0};
int dy[2] = {0, 1};

void bfs(int sx, int sy){
    visited[sx][sy] = true;
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<2; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(!visited[nx][ny] && map[nx][ny] == 1){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    
    bfs(0, 0);
    if(visited[m-1][n-1]){
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
