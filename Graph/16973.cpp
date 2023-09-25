#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, m, h, w;
int sx, sy, ex, ey;
int map[1001][1001];
bool visited[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool validcheck(int x, int y, int dir){ // x는 h, y는 w와 매칭
    if(dir == 0){ // 위로 이동
        // 현재 직사각형 기준 위 라인을 순회하면서 1의 존재를 찾는다.
        if(x-1 < 0) return false;
        for(int i=y; i<y+w; i++){
            if(map[x-1][i] == 1){
                return false;
            }
        }
        return true;
    } else if(dir == 1){ // 좌로 이동
        // 현재 직사각형 기준 좌측 라인을 순회하면서 1의 존재를 찾는다. 
        if(y-1 < 0) return false;
        for(int i=x; i<x+h; i++){
            if(map[i][y-1] == 1){
                return false;
            }
        }    
        return true;
    } else if(dir == 2){ // 아래로 이동
        // 현재 직사각형 기준 아래 라인을 순회하면서 1의 존재를 찾는다. 
        if(x+h >= n) return false;
        for(int i=y; i<y+w; i++){
            if(map[x+h][i] == 1){
                return false;
            }
        }    
        return true;
    } else { // 우로 이동
        // 현재 직사각형 기준 우측 라인을 순회하면서 1의 존재를 찾는다. 
        if(y+w >= m) return false;
        for(int i=x; i<x+h; i++){
            if(map[i][y+w] == 1){
                return false;
            }
        }    
        return true;
    }
}

void BFS(){
    queue<pair<pair<int, int>, int> > q;
    memset(visited, false, sizeof(visited));
    visited[sx][sy] = true;
    q.push(make_pair(make_pair(sx, sy), 0));
    if(sx == ex && sy == ey){
        cout << 0 << '\n';
        return;
    }

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if(y == ey && x == ex){
            cout << cnt << '\n';
            return;
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || map[nx][ny]) continue;
            if(validcheck(x, y, i) == true){
                q.push(make_pair(make_pair(nx, ny), cnt+1));
                visited[nx][ny] = true;
            }
        }
    }
    cout << -1 << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    cin >> h >> w >> sx >> sy >> ex >> ey;
    sx--;
    sy--;
    ex--;
    ey--;
    BFS();
    return 0;
}
