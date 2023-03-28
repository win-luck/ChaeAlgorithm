#include <iostream>
#include <queue>

using namespace std;
int n, m;
bool flag;
int map[101][71];
bool visited[101][71];
int dx[8] = {-1, 0, 1, 0, 1, 1, -1, -1}; // 인접하다는 8방향
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void BFS(int r, int c){
    queue<pair<int, int> > q;
    q.push(make_pair(r, c));
    visited[r][c] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue; // 범위 이탈
            if(map[r][c] < map[nx][ny]) flag = false; // 더 높은 산봉우리가 확인되었을 경우 flag는 false
            if(visited[nx][ny] || map[r][c] != map[nx][ny]) continue; // 주변의 같은 높이를 가지는 경우만 재탐색 허용
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
}

int main(){
    int cnt = 0;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j]){
                flag = true;
                BFS(i, j);
                if(flag) cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}