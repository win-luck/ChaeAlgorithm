#include <iostream>
#include <queue>

using namespace std;
int arr[5][5];
int visited[5][5] = {0, };
int sx, sy;
int answer = -1;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> arr[i][j];
        }
    }
    cin >> sx >> sy;

    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));
    visited[sx][sy] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(arr[x][y] == 1){
            answer = visited[x][y]-1;
            break;
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || visited[nx][ny] || arr[nx][ny] == -1) continue;
            q.push(make_pair(nx, ny));
            visited[nx][ny] = visited[x][y] + 1;
        }
    }
    cout << answer;
    return 0;
}
