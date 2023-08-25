#include <iostream>

using namespace std;
int n, t;
int dp[10001][4] = {0,}; // 정수 i를 만들 때 마지막으로 더한 수가 1~3인 경우의 수

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[3][1] = 1;
    dp[2][2] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for(int i=4; i<=10000; i++){ // 중복 회피를 위해 오름차순으로만 더할 수 있다 가정하자
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }
    while(t--){
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
    }
    return 0;
}