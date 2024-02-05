#include <iostream>
#include <algorithm>

using namespace std;
int t, n;
long long dp[68];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4; i<=67; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
    }

    cin >> t;
    while(t--){
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}
