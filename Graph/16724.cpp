#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[1001][1001];
int visited[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int result;

void DFS(int x, int y){
    visited[x][y] = 1;
    int nx = x + dx[map[x][y]];
    int ny = y + dy[map[x][y]];

    if(visited[nx][ny] == 1) result++;
    if(visited[nx][ny] == 0) DFS(nx, ny);
    visited[x][y] = 2; // 방문을 마쳤다는 표시, 재방문을 막기 위함.
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<m; j++){
            if(str[j] == 'U') map[i][j] = 1; // 이차원 배열에서 위로 한 칸 가려면 (-1, 0) 만큼 인덱스 이동
            else if(str[j] == 'L') map[i][j] = 2; // 이차원 배열에서 좌측으로 한 칸 가려면 (0, -1) 만큼 인덱스 이동
            else if(str[j] == 'R') map[i][j] = 3; // 이차원 배열에서 우측으로 한 칸 가려면 (0, 1) 만큼 인덱스 이동
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j] == 0){
                DFS(i, j);
            }
        }
    }
    cout << result;
}