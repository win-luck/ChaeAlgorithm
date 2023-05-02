#include <iostream>

using namespace std;
int n;
long long dp[31];

int main(){
    cin >> n;
    dp[0] = 0;
    dp[2] = 3;
    for(int i=4; i<=n; i++){
        if(i%2 == 0){
            dp[i] = dp[i-2] * 3;
            for(int j=i-4; j>=0; j--){
                dp[i] += dp[j] * 2;
            }
            dp[i] += 2;
        }
    }
    cout << dp[n];
    return 0;
}
/* 점화식
dp[2] = 3
dp[4] = dp[2] * 3 + 2
dp[6] = dp[4] * 3 + dp[2] * 2 + 2;
dp[8] = dp[6] * 3 + dp[4] * 2 + dp[2] * 2 + 2;
*/