#include <iostream>

using namespace std;
int n, m;
long long dp[1001][1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        dp[i][1] = 1;
    }
    for(int i=1; i<=m; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=n; i++){
        for(int j=2; j<=m; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + dp[i-1][j-1];
            dp[i][j] %= 1000000007;
        }
    }
    cout << dp[n][m];
    return 0;
}
