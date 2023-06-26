#include <iostream>
#include <queue>

using namespace std;
int n, m;
bool visited[601][601];
char map[601][601];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int> > q;

void BFS(int sx, int sy){
    int cnt = 0;
    visited[sx][sy] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        if(map[x][y] == 'P') cnt++;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == 'X') continue;
            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }

    if(cnt == 0){
        cout << "TT" << '\n';
    } else {
        cout << cnt << '\n';
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<m; j++){
            map[i][j] = str[j];
            if(map[i][j] == 'I'){
                q.push(make_pair(i, j));
            }
        }
    }
    BFS(q.front().first, q.front().second);
    return 0;
}