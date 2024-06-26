#include <iostream>

using namespace std;

int main(){
    int t, n, m;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n; // n가지 동전으로 m원 만들기
        int coin[n+1]; // n번째 코인
        for(int i=1; i<=n; i++){ // 코인 초기화
            cin >> coin[i];
        }
        cin >> m;
        int dp[m+1]; // m원 만드는 경우의 수
        dp[0] = 1;

        for(int i=1; i<=m; i++){ // 배열 초기화
            dp[i] = 0;
        }

        for(int i=1; i<=n; i++){
            for(int j=coin[i]; j<=m; j++){
                dp[j] = dp[j] + dp[j-coin[i]]; // i번째 코인의 값을 슥 넣으면 목표 가격에 딱 맞는 경우의 수를 더해준다.
            }
        }
        cout << dp[m] << '\n';
    }
    return 0;
}

/* 1/5/10원 사용
0 - 1 (1개)
1 - 1 (1개)
2 - 1/1 (1개)
3 - 1/1/1 (1개)
4 - 1/1/1/1 (1개)
5 - 1/1/1/1/1, 5 (2개)
6 - 1/1/1/1/1/1, 1/5 (2개)
7 - 1/1/1/1/1/1/1, 1/1/5 (2개)
8 - 1/1/1/1/1/1/1/1, 1/1/1/5 (2개)
9 - 1/1/1/1/1/1/1/1/1, 1/1/1/1/5 (2개)
10 - 1/1/1/1/1/1/1/1/1/1, 5/5, 10 (3개)
점화식 - dp[a] = dp[a] + dp[a - n번째 코인의 값]
*/