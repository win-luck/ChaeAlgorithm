#include <iostream>
#include <queue>

using namespace std;
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char map[101][101];
bool visited[101][101];

void BFS(int sx, int sy){
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
            if(map[nx][ny] == '#'){
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt = 0;

    cin >> n >> m;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<m; j++){
            map[i][j] = str[j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && map[i][j] == '#'){
                BFS(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
