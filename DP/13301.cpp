#include <iostream>
#include <algorithm>

using namespace std;
long long dp[81];

int main(){
    int n;
    cin >> n;
    dp[1] = 4;
    dp[2] = 6;
    dp[3] = 10;
    dp[4] = 16;
    for(int i=5; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
    return 0;
}