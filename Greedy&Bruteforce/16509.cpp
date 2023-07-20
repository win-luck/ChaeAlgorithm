#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int visited[10][9];
int sx, sy, ex, ey;
int dx[8] = {-3, -3, -2, 2, 3, 3, 2, -2};
int dy[8] = {-2, 2, 3, 3, 2, -2, -3, -3};

bool validcheck(int i, int x, int y){ // 진행한 방향에 돌이 존재하면 안 됨 
    if(i >= 1 && i <= 2){
        for(int j=1; j<=2; j++){
            if(x + j == ex && y - j == ey) return false;
        }
    } else if(i >= 3 && i <= 4){
        for(int j=1; j<=2; j++){
            if(x - j == ex && y - j == ey) return false;
        } 

    } else if(i >= 5 && i <= 6){
        for(int j=1; j<=2; j++){
            if(x - j == ex && y + j == ey) return false;
        }
    } else {
        for(int j=1; j<=2; j++){
            if(x + j == ex && y + j == ey) return false;
        }
    }
    return true;
}

void BFS(int sx, int sy){
    int cnt = 0;
    queue<pair<int, int> > q;
    visited[sx][sy] = 1;
    q.push(make_pair(sx, sy));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        if(x == ex && y == ey){
            cout << visited[ex][ey]-1;
            return;
        }

        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= 10 || ny >= 9) continue;
            if(visited[nx][ny]) continue;
            if(validcheck(i, nx, ny)){
                visited[nx][ny] = visited[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    cout << -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> sx >> sy;
    cin >> ex >> ey;
    BFS(sx, sy);
    return 0;
}