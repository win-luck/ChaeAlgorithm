#include <iostream>

using namespace std;
int n;
int dp[10][3];

int main(){
    cin >> n;

    dp[1][0] = 0; // 0으로 시작하는 수는 만들 수 없다.
    dp[1][1] = 1; // 1
    dp[1][2] = 1; // 2
    dp[2][0] = 2; // 21, 12
    dp[2][1] = 2; // 10, 22
    dp[2][2] = 2; // 20, 11

    for(int i=3; i<=n; i++){
        for(int j=0; j<3; j++){
            dp[i][j] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
        }
    }

    cout << dp[n][0];
}