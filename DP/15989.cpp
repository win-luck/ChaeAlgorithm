#include <iostream>

using namespace std;
int n;
long long dp[36];

int main(){
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    for(int i=4; i<=n; i++){
        for(int j=0; j<i; j++){
            dp[i] += (dp[j] * dp[i-1-j]);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}