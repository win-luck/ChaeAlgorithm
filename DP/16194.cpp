#include <iostream>
#include <algorithm>

using namespace std;
int n;
int dp[1001] = {0,};
int card[10001] = {0,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> card[i];
    }
    fill(dp, dp+1001, 987654321);
    
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] = min(dp[i], dp[i-j] + card[j]);
        }
    }
    cout << dp[n];
    return 0;
}
