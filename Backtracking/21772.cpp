#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int r, c, lim;
int sx, sy;
char arr[101][101];
bool visited[101][101];
int answer = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, int depth, int cnt){
    if(depth >= lim){
        answer = max(answer, cnt);
        return;
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= r || ny >= c || arr[nx][ny] == '#') continue;
        if(arr[nx][ny] == 'S'){
            arr[nx][ny] = '.';
            dfs(nx, ny, depth+1, cnt+1);
            arr[nx][ny] = 'S';
        } else {
            dfs(nx, ny, depth+1, cnt);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c >> lim;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'G'){
                sx = i;
                sy = j;
                arr[i][j] = '.';
            }
        }
    }

    dfs(sx, sy, 0, 0);
    cout << answer;
    return 0;
}
