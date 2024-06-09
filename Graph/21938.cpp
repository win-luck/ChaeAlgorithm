#include <iostream>
#include <queue>

using namespace std;
int n, m, t;
int arr[1001][1001];
bool visited[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int sx, int sy){
    queue<pair<int, int> > q;
    visited[sx][sy] = true;
    q.push(make_pair(sx, sy));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny]) continue;
            if(arr[nx][ny] == 0) continue;
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int a, b, c;
            cin >> a >> b >> c;
            arr[i][j] = (a+b+c) / 3;
        }
    }

    cin >> t;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] >= t){
                arr[i][j] = 255;
            } else {
                arr[i][j] = 0;
            }
        }
    }

    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 255 && !visited[i][j]){
                bfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
