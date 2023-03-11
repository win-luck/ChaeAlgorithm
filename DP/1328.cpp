#include <iostream>
#include <cstring>

using namespace std;
int N, L, R;
long long dp[101][101][101];

int main(){
    cin >> N >> L >> R;

    memset(dp, 0, sizeof(dp));
    dp[1][1][1] = 1;

    for(int i=2; i<=N; i++){
        for(int j=1; j<=i; j++){
            for(int k=1; k<=i; k++){
                dp[i][j][k] = (dp[i-1][j-1][k] + dp[i-1][j][k-1] + dp[i-1][j][k] * (i-2)) % 1000000007;
                // 모든 건물이 왼 -> 오로 가면서 내림차순으로 생긴다고 하자.
                // 이때 좌끝에 새 건물을 두면 j가 증가하고 오른쪽 시선엔 변화가 없고, 반대로 우끝에 건물을 두면 k가 증가하고 왼쪽 시선엔 변화가 없다.
            } // 이후 좌끝도 우끝도 아닌 경우는 (i-2)개 만큼 존재하며, 좌 우 모두 안 보인다.
        }
    }
    cout << dp[N][L][R];
    return 0;
}