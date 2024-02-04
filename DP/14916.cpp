#include <iostream>
#include <algorithm>

using namespace std;
long long dp[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = -1;
    dp[2] = 1;
    dp[3] = -1;
    dp[4] = 2;
    dp[5] = 1;
    for(int i=6; i<=n; i++){
        if(dp[i-2] != -1)
            dp[i] = dp[i-2] + 1;
        if(dp[i-5] != -1)
            dp[i] = min(dp[i], dp[i-5] + 1);
    }
    cout << dp[n];
    return 0;
}
