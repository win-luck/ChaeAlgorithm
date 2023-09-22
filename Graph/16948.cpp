#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int visited[201][201];
int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};
int n, sx, sy, ex, ey;

void BFS(int sx, int sy){
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));
    visited[sx][sy] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        if(x == ex && y == ey){
            cout << visited[ex][ey]-1;
            return;
        }

        for(int i=0; i<6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(!visited[nx][ny]){
                visited[nx][ny] = visited[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    cout << -1;
}

int main(){
    cin >> n;
    cin >> sx >> sy >> ex >> ey;
    BFS(sx, sy);
    return 0;
}
