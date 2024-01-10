#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int n;
int result = 0;
int map[505][505];
int origin[505][505];
bool visited[505][505];
int dx[4] = {0, 1, 0, -1}; // 좌하우상 순서로 반복
int dy[4] = {-1, 0, 1, 0};
int nowdir = 0;

void tonado(int sx, int sy){
    visited[sx][sy] = true;
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == 2 && y == 2) break; // 종료조건

        int nx = x + dx[nowdir];
        int ny = y + dy[nowdir];
        int val = map[nx][ny]; // 퍼질 모래의 원래 양
        map[nx][ny] = 0;

        int one = val / 100;
        int two = (val * 2) / 100;
        int five = (val * 5) / 100;
        int seven = (val * 7) / 100;
        int ten = (val * 10) / 100;
        int alpha = val - five - 2*(one + two + seven + ten);
        
        if(nowdir == 0){ // 좌
            map[nx][ny-1] += alpha;
            map[nx][ny-2] += five;
            map[nx-1][ny-1] += ten;
            map[nx+1][ny-1] += ten;

            map[nx-1][ny] += seven;
            map[nx+1][ny] += seven;

            map[nx+2][ny] += two;
            map[nx-2][ny] += two;

            map[nx+1][ny+1] += one;
            map[nx-1][ny+1] += one;
        } else if(nowdir == 1){ // 하
            map[nx+1][ny] += alpha;
            map[nx+2][ny] += five;

            map[nx+1][ny+1] += ten;
            map[nx+1][ny-1] += ten;

            map[nx][ny+1] += seven;
            map[nx][ny-1] += seven;

            map[nx][ny+2] += two;
            map[nx][ny-2] += two;

            map[nx-1][ny-1] += one;
            map[nx-1][ny+1] += one;
        } else if (nowdir == 2){ // 우
            map[nx][ny+1] += alpha;
            map[nx][ny+2] += five;
            map[nx+1][ny+1] += ten;
            map[nx-1][ny+1] += ten;

            map[nx-1][ny-1] += one;
            map[nx+1][ny-1] += one;

            map[nx+1][ny] += seven;
            map[nx-1][ny] += seven;

            map[nx+2][ny] += two;
            map[nx-2][ny] += two;
        } else { // 상
            map[nx-1][ny] += alpha;
            map[nx-2][ny] += five;
            map[nx+1][ny+1] += one;
            map[nx+1][ny-1] += one;

            map[nx][ny+1] += seven;
            map[nx][ny-1] += seven;

            map[nx][ny+2] += two;
            map[nx][ny-2] += two;

            map[nx-1][ny-1] += ten;
            map[nx-1][ny+1] += ten;
        }
        // 다음 방향은 꺾어야 하는가? 에 대한 판정
        int cnt = 0;
        for(int i=0; i<4; i++){
            if(!visited[nx + dx[i]][ny + dy[i]]) cnt++;
        }
        if(cnt == 3){
            nowdir = (nowdir+1) % 4;
        }

        q.push(make_pair(nx, ny));
        visited[nx][ny] = true;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    memset(map, 0, sizeof(map));
    memset(origin, 0, sizeof(origin));
    for(int i=2; i<=n+1; i++){
        for(int j=2; j<=n+1; j++){
            cin >> map[i][j];
            origin[i][j] = 1;
        }
    }
    tonado((n+4)/2, (n+4)/2);
    for(int i=0; i<=n+3; i++){
        for(int j=0; j<=n+3; j++){
            if(origin[i][j] != 1){ // 외곽 지역
                result += map[i][j];
            }
        }
    }
    cout << result;
    return 0;
}
