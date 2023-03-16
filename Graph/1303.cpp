#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int n, m;
char map[101][101];
int visited[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int s = 1;
int our = 0;
int enemy = 0;

void BFS(int r, int c, char t){
    queue<pair<int, int> > q;
    visited[r][c] = true;
    q.push(make_pair(r, c));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] || map[nx][ny] != t) continue;

            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
            s++;
        }
    }
}

int main(){
    cin >> m >> n;
    string str;

    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<m; j++){
            map[i][j] = str[j];
        }
    }

    // 먼저 적부터 계산
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 'B' && !visited[i][j]){
                BFS(i, j, 'B');
                enemy += s * s; // BFS 후 적이 n개면 n제곱 더해주기
                s = 1;
            }
        }
    }

    // 방문 여부 초기화
    memset(visited, false, sizeof(visited));
    
    // 아군 계산
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 'W' && !visited[i][j]){
                BFS(i, j, 'W');
                our += s * s;
                s = 1;
            }
        }
    }

    cout << our << " " << enemy;
    return 0;
}