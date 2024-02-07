#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int k, w, h;
int map[200][200];
int visited[31][200][200];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dxh[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dyh[8] = {2, -2, 1, -1, -2, 2, -1, 1};

void bfs(){
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(k, make_pair(0, 0)));
    visited[k][0][0] = 1;
    int answer = 987654321;

    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int t = q.front().first;
        q.pop();

        if(x == h-1 && y == w-1){
            cout << visited[t][x][y]-1;
            return;
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= h || ny >= w || visited[t][nx][ny] || map[nx][ny])
                continue;
            q.push(make_pair(t, make_pair(nx, ny)));
            visited[t][nx][ny] = visited[t][x][y] + 1; 
        }

        if(t >= 1){
            for(int i=0; i<8; i++){
                int nx = x + dxh[i];
                int ny = y + dyh[i];
                if(nx < 0 || ny < 0 || nx >= h || nx >= w || visited[t-1][nx][ny] || map[nx][ny])
                    continue; 
                q.push(make_pair(t-1, make_pair(nx, ny)));
                visited[t-1][nx][ny] = visited[t][x][y] + 1; 
            }
        }
    }
    cout << -1;
}

void input(){
    cin >> k;
    cin >> w >> h;
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> map[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    bfs();
    return 0;
}
