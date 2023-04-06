#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int t, n, m;
string str;
char map[101][101];
bool visited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int r, int c){
    queue<pair<int, int > > q;
    q.push(make_pair(r, c));
    visited[r][c] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(map[nx][ny] == '#' && !visited[nx][ny]){
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main(){
    cin >> t;
    for(int a=0; a<t; a++){
        int cnt = 0;
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));

        cin >> n >> m;

        for(int i=0; i<n; i++){
            cin >> str;
            for(int j=0; j<m; j++){
                map[i][j] = str[j];
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(map[i][j] == '#' && !visited[i][j]){
                    BFS(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}