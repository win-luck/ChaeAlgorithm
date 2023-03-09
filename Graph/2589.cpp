#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int n, m;
int res = -1;
char map[51][51];
bool visited[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int r, int c, int cnt){
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(r, c), cnt));
    visited[r][c] = true;
    int move = 0;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int movecnt = q.front().second;
        q.pop();

        move = max(move, movecnt); // 육지에서 가장 많이 움직인 횟수를 찾아야 한다.

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == 'W' || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push(make_pair(make_pair(nx, ny), movecnt + 1));
        }
    }
    res = max(res, move); // 최단거리 갱신
}


void input(){
    string str;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<m; j++){
            map[i][j] = str[j];
        }
    }
}

int main(){
    input();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 'L'){ // 각 육지마다 출발점으로 잡고 BFS
                BFS(i, j, 0);
                memset(visited, false, sizeof(visited));
            }
        }
    }

    cout << res << '\n';
    return 0;
}