#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int visited[1000][1000][2]; // 최단거리 저장
int n, m, sx, sy, ex, ey;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int map[1000][1000];

void BFS(int sx, int sy){
    queue<pair<pair<int,int>, int> > q;
    q.push(make_pair(make_pair(sx-1, sy-1), 1));
    visited[sx-1][sy-1][1] = 1;

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int breakflag = q.front().second;
        q.pop();

        if(r == ex-1 && c == ey-1){ // 도착
            cout << visited[r][c][breakflag]-1 << '\n';
            return;
        }

        for(int i=0; i<4; i++){
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                if(map[nr][nc] == 0 && visited[nr][nc][breakflag] == 0){ // 단순히 아직 가지 않은 길을 지날 때
                    q.push(make_pair(make_pair(nr, nc), breakflag));          
                    visited[nr][nc][breakflag] = visited[r][c][breakflag] + 1;
                } else if(map[nr][nc] == 1 && breakflag == 1){ // 벽이 있고 깰 수 있을 때
                    q.push(make_pair(make_pair(nr, nc), breakflag-1));
                    visited[nr][nc][breakflag-1] = visited[r][c][breakflag] + 1;
                }
            }
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> sx >> sy;
    cin >> ex >> ey;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    memset(visited, 0, sizeof(visited));
    BFS(sx, sy);
    return 0;
}