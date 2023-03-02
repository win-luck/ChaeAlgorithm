#include <iostream>

using namespace std;

int n, result;
int map[501][501];
int dp[501][501];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void input(){
    result = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
}

int DFS(int a, int b){ // DFS를 통해 판다의 출발점을 순회하며 최대값을 저장한다.
    if(dp[a][b] != 0) return dp[a][b]; // 메모이제이션
    dp[a][b] = 1;

    for(int i=0; i<4; i++){
        int nx = a + dx[i];
        int ny = b + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(map[nx][ny] > map[a][b]){ // 자리를 옮기려면 현재 지역보다 큰 숫자여야 한다.
            dp[a][b] = max(dp[a][b], DFS(nx, ny) + 1);
        }
    }
    return dp[a][b];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            result = max(result, DFS(i, j));
        }
    }
    cout << result << '\n';
    return 0;
}