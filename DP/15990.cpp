#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    long long dp[100001][4];
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1; // 선두가 1인 경우
    dp[3][2] = 1; // 선두가 2인 경우
    dp[3][3] = 1; // 선두가 3인 경우

    for(int i=4; i<=100000; i++){
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % 1000000009;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % 1000000009;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % 1000000009;
    }

    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009 << '\n';
    }
    return 0;
}
