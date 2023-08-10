#include <iostream>
#include <stack>

using namespace std;
int t, n;
long long dp[2501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=2500; i++){
        for(int j=0; j<i; j++){
            // dp[3] = dp[0]*dp[2] + dp[1]*dp[1] + dp[2]*dp[0]
            dp[i] += dp[j] * dp[i-j-1];
            dp[i] %= 1000000007;
        }
    }

    cin >> t;
    for(int a=0; a<t; a++){
        // 홀수는 무조건 0이므로 2500까지만 카운트한다.
        cin >> n;
        cout << ((n % 2 == 1) ? 0 : dp[n/2]) << '\n';
    }
    return 0;
}
