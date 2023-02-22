#include <iostream>
#include <queue>

using namespace std;

struct Dot {
    int x;
    int y;
    int day;

    Dot(int inputx, int inputy, int d){
        x = inputx;
        y = inputy;
        day = d;
    }
};

int m, n;
int map[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<Dot> q;

bool validcheck() {
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0) return false;
        }
    }
    return true;
}

void BFS() {
    int totalday = 0;

    while(!q.empty()){
        Dot dot = q.front();
        q.pop();
        totalday = dot.day;

        for(int i=0; i<4; i++){
            int nx = dot.x + dx[i];
            int ny = dot.y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if(map[nx][ny] == 0){
                map[nx][ny] = 1;
                q.push(Dot(nx, ny, dot.day + 1));
            }
        }
    }

    if(validcheck()){
        cout << totalday << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                q.push(Dot(i, j, 0));
            }
        }
    }
    BFS();
    return 0;
}