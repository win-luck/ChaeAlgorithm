#include <iostream>

using namespace std;
int n;
long long dp[1000001];

int main(){
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }
    cout << dp[n];
}

/** 0은 오직 00의 단위로만 추가된다.
 * 1 - 1
 * 2 - 11, 00
 * 3 - 100, 001, 111
 * 4 - 0000, 0011, 1100, 1111, 1001
 * 5 - 11111, 11100, 00111, 10011, 11001, 10000, 00001, 00100
 * 점화식 - dp[k] = dp[k-1] + dp[k-2]
*/