#include <iostream>
#include <queue>

using namespace std;
int n, m, k;
int res = 0;
int map[101][101] = { 0, };
bool visited[101][101] = { 0, };
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int r, int c){ // 평범한 BFS
    queue<pair<int, int> > q;
    int cnt = 0;
    q.push(make_pair(r, c));
    visited[r][c] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cnt++;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(map[nx][ny] == 1 && !visited[nx][ny]){
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
    res = max(res, cnt);
}

int main(){
    cin >> n >> m >> k;
    for(int i=0; i<k; i++){
        int a, b;
        cin >> a >> b;
        map[a-1][b-1] = 1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 1 && !visited[i][j]){
                BFS(i, j);
            }
        }
    }
    cout << res << '\n';
    return 0;
}