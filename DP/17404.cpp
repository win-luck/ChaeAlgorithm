#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v[1001][3]; // 각 집의 칠하는 비용
int result = 100000000;

int main(){
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=2; j++){
            int a;
            cin >> a;
            v[i][j] = a;
        }
    } // 입력 

    for(int begin=0; begin<=2; begin++){ // begin은 첫 번째 색깔을 의미
        int dp[1001][3]; // 색깔마다 매번 초기화
        for(int j=0; j<=2; j++){
            if(j == begin) dp[1][begin] = v[1][begin]; // 최초 dp값은 1번째 값 제외하고 모두 최대치로 맞춰둔다.
            else dp[1][j] = 1001;
        }

        for(int i=2; i<=N; i++){ // bottom-up 방식의 DP
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + v[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + v[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + v[i][2];
        }
        
        for(int j=0; j<=2; j++){ // 첫 색과 마지막 색이 같은 경우 배제
            if(j == begin) continue;
            else result = min(result, dp[N][j]);
        }
    }

    cout << result << endl;
    return 0;
}


