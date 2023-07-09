#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
int l, r, c;
int visited[31][31][31];
char map[31][31][31];
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

struct pos{
    int x, y, z;
    pos(int ax, int ay, int az){
        x = ax;
        y = ay;
        z = az;
    }
};

int sx, sy, sz, fx, fy, fz;

void BFS(int sx, int sy, int sz){
    queue<pos> q;
    visited[sx][sy][sz] = 1;
    q.push(pos(sx, sy, sz));

    while(!q.empty()){
        pos p = q.front();
        q.pop();

        if(p.x == fx && p.y == fy && p.z == fz){
            cout << "Escaped in " << visited[fx][fy][fz] - 1 << " minute(s)." << '\n';
            return;
        }

        for(int i=0; i<6; i++){
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            int nz = p.z + dz[i];

            if(nx < 0 || ny < 0 || nz < 0 || nx >= l || ny >= r || nz >= c) continue;
            if(map[nx][ny][nz] == '#') continue;
            if(!visited[nx][ny][nz]){
                visited[nx][ny][nz] = visited[p.x][p.y][p.z] + 1;
                q.push(pos(nx, ny, nz));
            }
        }
    }
    cout << "Trapped!" << '\n'; // 불가능한 경우
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(1){
        memset(visited, 0, sizeof(visited));
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0){
            break;
        }

        for(int i=0; i<l; i++){
            for(int j=0; j<r; j++){
                string str;
                cin >> str;
                for(int k=0; k<c; k++){
                    map[i][j][k] = str[k];
                    if(str[k] == 'S'){
                        sx = i;
                        sy = j;
                        sz = k;
                    }
                    if(str[k] == 'E'){
                        fx = i;
                        fy = j;
                        fz = k;
                    }
                }
            }
        }
        BFS(sx, sy, sz);
    }
    return 0;
}