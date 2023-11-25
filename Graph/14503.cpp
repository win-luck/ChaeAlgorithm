#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int n, m, sx, sy, startdir;
int arr[51][51];
int visited[51][51];
int dx[4] = {-1, 0, 1, 0}; // 북-동-남-서
int dy[4] = {0, 1, 0, -1};
int cnt = 0;

void BFS(){
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(startdir, make_pair(sx, sy)));
    visited[sx][sy] = true;
    cnt = 1;

    while(!q.empty()){
        int nowdir = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        bool flag = false;

        for(int i=0; i<4; i++){
            int nr = nowdir - 1;
            if(nr == -1) 
                nr = 3; // 반시계 회전
            int nx = x + dx[nr];
            int ny = y + dy[nr];

            if(visited[nx][ny] || arr[nx][ny] == 1){ // 실패 -> 또 반시계 회전해야 함
                nowdir = nr;
                continue;
            }
            if(!visited[nx][ny] && arr[nx][ny] == 0){ // 청소되지 않은 빈 칸이 있는 경우
                q.push(make_pair(nr, make_pair(nx, ny)));
                visited[nx][ny] = true;
                flag = true;
                cnt++;
                break;
            }
        }
        if(!flag){ // 모든 칸이 청소되었거나 청소할 수 없음 -> 후진
            int rx = x - dx[nowdir];
            int ry = y - dy[nowdir];
            if(arr[rx][ry] == 0) {
                q.push(make_pair(nowdir, make_pair(rx, ry)));
            }
        }
    }
}

int main(){
    cin >> n >> m;
    cin >> sx >> sy >> startdir;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    BFS();
    cout << cnt;
    return 0;
}
