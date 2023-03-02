#include <iostream>
#include <cstring>

using namespace std;
int n, T;
long long dp[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--){
        memset(dp, 0, sizeof(dp));
        cin >> n;
        
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i=4; i<=n; i++){
            dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;
        }
        cout << dp[n] << '\n';
    }
    return 0;
}
/**
 * 1 - 1
 * 2 - 2
 * 3 - 4
 * 4 - 7
 * 5 - 13
 * 6 - 24
 * 점화식 -> dp[k] = dp[k-1] + dp[k-2] + dp[k-3]
*/