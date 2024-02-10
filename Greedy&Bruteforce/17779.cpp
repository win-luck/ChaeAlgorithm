#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int total = 0;
int map[21][21];
int popular[21][21];
bool visited[21][21];
int n;
int answer = 987654321;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool validcheck(int x, int y){
    if(x < 1 || y < 1 || x > n || y > n) return false;
    return true;
}

void bfs(int sx, int sy){
    queue<pair<int, int> > q;
    visited[sx][sy] = true;
    map[sx][sy] = 5;
    q.push(make_pair(sx, sy));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || ny < 1 || nx > n || ny > n || visited[nx][ny]) continue;
            if(map[nx][ny] == 0){
                map[nx][ny] = 5;
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }

    for(int i=2; i<=n-1; i++){ // 외딴섬 형태로 5로 둘러싸인 곳 예외처리
        for(int j=2; j<=n-1; j++){
            if(map[i+1][j] == 5 && map[i][j+1] == 5 && map[i-1][j] == 5 && map[i][j-1] == 5)
                map[i][j] = 5;
        }
    }
}

int part(int x, int y, int d1, int d2, int pos){
    int sum = 0;
    if(pos == 1){
        for(int i=1; i<x+d1; i++){
            for(int j=1; j<=y; j++){
                if(map[i][j] != 5) {
                    map[i][j] = 1;
                    sum += popular[i][j];
                }
            }
        }
    } else if(pos == 2){
        for(int i=1; i<=x+d2; i++){
            for(int j=y+1; j<=n; j++){
                if(map[i][j] != 5) {
                    map[i][j] = 2;
                    sum += popular[i][j];
                }
            }
        }
    } else if(pos == 3){
        for(int i=x+d1; i<=n; i++){
            for(int j=1; j<y-d1+d2; j++){
                if(map[i][j] != 5) {
                    map[i][j] = 3;
                    sum += popular[i][j];
                }
            }
        }
    } else {
        for(int i=x+d2+1; i<=n; i++){
            for(int j=y-d1+d2; j<=n; j++){
                if(map[i][j] != 5) {
                    map[i][j] = 4;
                    sum += popular[i][j];
                } 
            }
        }
    }
    return sum;
}

bool divide(int x, int y, int d1, int d2){ // 선거구 분할
    memset(map, 0, sizeof(map));
    memset(visited, false, sizeof(visited));
    map[x][y] = 5;

    for(int s=x+1, e=y-1; s!=x+d1 && e!=y-d1; s++, e--){ // 왼쪽 위 대각선
        if(!validcheck(s, e)) return false;
        map[s][e] = 5;
    }

    for(int s=x+1, e=y+1; s!=x+d2 && e!=y+d2; s++, e++){ // 오른쪽 위 대각선
        if(!validcheck(s, e)) return false;
        map[s][e] = 5;
    }

    for(int s=x+d1, e=y-d1; s!=x+d1+d2 && e!=y-d1+d2; s++, e++){ // 왼쪽 아래 대각선
        if(!validcheck(s, e)) return false;
        map[s][e] = 5;
    }

    for(int s=x+d1+d2, e=y-d1+d2; s!=x+d2-1 && e!=y+d2+1; s--, e++){ // 오른쪽 아래 대각선
        if(!validcheck(s, e)) return false;
        map[s][e] = 5;
    }

    bfs(x+1, y); // 사각형 내부 bfs로 5로 채움
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> popular[i][j];
            total += popular[i][j];
        }
    }

    for(int x=1; x<=n; x++){
        for(int y=1; y<=n; y++){
            for(int d1=1; d1<=n; d1++){
                for(int d2=1; d2<=n; d2++){
                    if(!divide(x, y, d1, d2)) continue; // 분할 불가능하면 패스

                    int arr[5];
                    arr[1] = part(x, y, d1, d2, 1);
                    arr[2] = part(x, y, d1, d2, 2);
                    arr[3] = part(x, y, d1, d2, 3);
                    arr[4] = part(x, y, d1, d2, 4);
                    arr[0] = total - (arr[1]+arr[2]+arr[3]+arr[4]); // 5선거구

                    bool flag = true;
                    for(int i=0; i<5; i++){ // 선거구는 구역을 적어도 하나 포함하므로 1 이상
                        if(arr[i] <= 0){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        sort(arr, arr+5);
                        int now = arr[4] - arr[0];
                        answer = min(answer, now);
                    }
                }
            }
        }
    }
    cout << answer;
    return 0;
}
