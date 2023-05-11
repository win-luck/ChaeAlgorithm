#include <iostream>

using namespace std;
int n;
long long dp[101] = {0,};

int main(){
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    // 점화식
    // 현재 = 직전+1 또는 2~4 & 4 반복하는 경우 dp[i-실행횟수] * (실행횟수-1)이 된다.
    // 예를 들어 dp[4] = dp[1] * 2가 된다. (처음 1번인 dp[1]에다가 복붙하는 데 3번 기회를 사용한다.)
    for(int i=4; i<=n; i++){
        dp[i] = dp[i-1] + 1; // 초기 비교 값
        for(int j=3; j<=i; j++){
            dp[i] = max(dp[i], dp[i-j] * (j-1));
        }
    }
    cout << dp[n];
    return 0;
}