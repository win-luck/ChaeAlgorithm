#include <iostream>
#include <cstring>

using namespace std;
int T, n;
long long dp[2][100001];
int map[2][100001];

int main(){
    cin >> T;
    while(T--){
        memset(dp, 0, sizeof(dp)); // 케이스마다 초기화
        memset(map, 0, sizeof(map));

        cin >> n;
        for(int j=0; j<2; j++){
            for(int i=0; i<n; i++){
                cin >> map[j][i];
            }
        }

        dp[0][0] = map[0][0];
        dp[1][0] = map[1][0];
        dp[0][1] = map[0][1] + dp[1][0];
        dp[1][1] = map[1][1] + dp[0][0]; // 대각선

        for(int i=2; i<n; i++){
            dp[0][i] = map[0][i] + max(dp[1][i-1], dp[1][i-2]); // 브이의 끝 vs 먼 대각선의 끝
            dp[1][i] = map[1][i] + max(dp[0][i-1], dp[0][i-2]);
        }

        cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
    }
    return 0;
}
/** 뗄 수 있는 스티커의 점수의 최댓값
 * 1 - 둘 중 하나
 * 2 - 대각선
 * 3 - 위브이 아래브이, 먼 대각선 2개
 * 4 - 피보나치같은 단순 수식적 규칙성 찾기 불가능하다는 것을 확인,
 * dp로 브이와 대각선에 대한 점화식 작성 필요
*/