#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int n, m;
char map[1001][1001];
int visited[1001][1001];
int f_visited[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int> > fireq;
queue<pair<int ,int> > q;

void bfs_fire(){
    while(!fireq.empty()){
        int x = fireq.front().first;
        int y = fireq.front().second;
        fireq.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(map[nx][ny] == '#' || f_visited[nx][ny]) continue;
            fireq.push(make_pair(nx, ny));
            f_visited[nx][ny] = f_visited[x][y] + 1;
        }
    }
}

int bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                return visited[x][y];
            }
            if(map[nx][ny] == '#' || visited[nx][ny]) continue;
            if(f_visited[nx][ny] > 0 && f_visited[nx][ny] <= visited[x][y]+1) continue;
            q.push(make_pair(nx, ny));
            visited[nx][ny] = visited[x][y] + 1;
        }
    }
    return -1;
}

void input(){
    cin >> m >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<m; j++){
            map[i][j] = str[j];
            if(map[i][j] == '@'){
                q.push(make_pair(i, j));
                visited[i][j] = 1;
            }
            if(map[i][j] == '*'){
                fireq.push(make_pair(i, j));
                f_visited[i][j] = 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        input();
        if(!fireq.empty()){
            bfs_fire();
        }
        int a = bfs();
        if(a == -1){
            cout << "IMPOSSIBLE\n";
        } else {
            cout << a << '\n';
        }

        while(!q.empty()) q.pop();
        while(!fireq.empty()) fireq.pop();
        memset(visited, 0, sizeof(visited));
        memset(f_visited, 0, sizeof(f_visited));
    }
    return 0;
}
