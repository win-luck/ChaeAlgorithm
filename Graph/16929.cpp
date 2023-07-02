#include <iostream>

using namespace std;
int n, m;
bool flag;
char map[51][51];
bool visited[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool DFS(int x, int y, int pastx, int pasty, char c){
    if(visited[x][y]) return true; // true면 사이클이 형성된 것이다.
    
    visited[x][y] = true; // 현재 노드 방문처리
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(map[nx][ny] != c) continue;
        if(nx != pastx || ny != pasty){ // 직전 노드를 다시 방문하면 안 된다.
            if(DFS(nx, ny, x, y, c)) return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<m; j++){
            map[i][j] = str[j];
        }
    } // 입력

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j]){
                if(DFS(i, j, 51, 51, map[i][j])){
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }

    cout << "No";
    return 0;
}