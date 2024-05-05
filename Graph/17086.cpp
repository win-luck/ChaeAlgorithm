#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int n, m;
int visited[51][51];
int map[51][51];
int answer = -1;
queue<pair<int, int> > q;
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    memset(visited, -1, sizeof(visited));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                q.push(make_pair(i, j));
                visited[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] > 0 || map[nx][ny] == 1) continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            answer = max(answer, visited[i][j]);
        }
    }
    cout << answer;
    return 0;
}
