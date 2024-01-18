#include <iostream>
#include <vector>

using namespace std;
int n, m, x, y, k;
int dx[5] = {0, 0, 0, -1, 1}; // 동서북남
int dy[5] = {0, 1, -1, 0, 0};
int map[21][21];
int dice[6]; // 주사위의 각 면 (인덱스 0이 6 역할)

void movedice(int dir){
    int tmp = dice[0];
    if(dir == 1){ // 동
        dice[0] = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[4];
        dice[4] = tmp;
    } else if(dir == 2){ // 서
        dice[0] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[3];
        dice[3] = tmp;
    } else if(dir == 3){ // 북
        dice[0] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[5];
        dice[5] = tmp;
    } else { // 남
        dice[0] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[2];
        dice[2] = tmp;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x >> y >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    dice[0] = map[x][y];

    for(int i=0; i<k; i++){
        int dir;
        cin >> dir;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx >= 0 && ny >= 0 && nx < n && ny < m){
            movedice(dir);
            if(map[nx][ny] == 0){
                map[nx][ny] = dice[0];
            } else {
                dice[0] = map[nx][ny];
                map[nx][ny] = 0;
            }
            x = nx;
            y = ny;
            cout << dice[1] << '\n';
        }
    }
    return 0;
}
