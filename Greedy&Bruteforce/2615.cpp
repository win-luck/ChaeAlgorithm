#include <iostream>
#define MAX 19

using namespace std;
int board[MAX][MAX];
int flag = 0;
int dx[4] = {0, 1, 1, -1};
int dy[4] = {1, 0, 1, 1};

bool isWin(int x, int y){
    int val = board[x][y];
    for(int i=0; i<4; i++){
        bool flag = true;
        for(int j=1; j<=4; j++){
            int nx = x + dx[i] * j;
            int ny = y + dy[i] * j;
            if(nx < 0 || nx >= MAX || ny < 0 || ny >= MAX || board[nx][ny] != val){
                flag = false;
                break;
            }
        }
        if(!flag) continue;

        // 6연속인지 판정
        int nx = x + dx[i]*5;
        int ny = y + dy[i]*5;
        if(nx >= 0 && nx < MAX && ny >= 0 && ny < MAX){
            if(board[nx][ny] == val){
                continue;
            }
        }
        nx = x - dx[i];
        ny = y - dy[i];
        if(nx >= 0 && nx < MAX && ny >= 0 && ny < MAX){
            if(board[nx][ny] == val){
                continue;
            }
        }

        if(flag) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            cin >> board[i][j];
        }
    }

    int winner = 0;
    int x, y;
    for(int i=0; i<MAX; i++){
        bool flag = false;
        for(int j=0; j<MAX; j++){
            if(board[i][j] != 0 && isWin(i, j)){
                winner = board[i][j];
                x = i+1;
                y = j+1;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }

    cout << winner << '\n';
    if(winner != 0){
        cout << x << " " << y;
    }
    return 0;
}
