#include <iostream>
#include <queue>

using namespace std;
int n;
int result = 0;
int map[101][101];
long long dp[101][101];

void BFS(int sx, int sy){
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == n-1 && j == n-1) return;
            if(dp[i][j] != 0){
                int rx = i;
                int ry = j + map[i][j];
                int dx = i + map[i][j];
                int dy = j;
                if(ry < n) dp[rx][ry] += dp[i][j];
                if(dx < n) dp[dx][dy] += dp[i][j];
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;
    BFS(0, 0);
    cout << dp[n-1][n-1] << '\n';
    return 0;
}