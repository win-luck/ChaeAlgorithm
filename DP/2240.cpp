#include <iostream>

using namespace std;
int t, w;
int pos = 1;
int res = 0;
int dp[1001][31][2];
int jadu[1001];

// 자두가 떨어지는 나무가 1 또는 2로 주어지고, 최초엔 1에 서 있다.
// 사람이 서 있는 곳도 생각하려면 3차원 DP로 생각해볼 수 있다.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t >> w;
    for(int i=1; i<=t; i++){
        cin >> jadu[i];
    }

    if(jadu[1] == 1){
        dp[1][0][1] = 1; // 0번 움직여 1번 나무에서 1번째 자두를 받는 경우
    } else {
        dp[1][1][0] = 1; // 1번 움직여 2번 나무에서 1번째 자두를 받는 경우
    }

    // 3차원 배열 상황이 어색해 고민이 길었던 문제.

    for(int i=2; i<=t; i++){
        for(int j=0; j<=w && j<t; j++){
            if(jadu[i] == 1){ // 현재 자두가 1번 나무에서 떨어짐
                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1] + 1); // 1번 아래에 서 있는 경우
                if(j < w && j < t-1) // 자리를 바꿀 수 있는 상황에서
                    dp[i][j+1][1] = max(dp[i][j+1][1], dp[i-1][j][0]+1); // 2번으로 자리를 바꾸어 받아먹는 경우

                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0]); // 2번 나무에서 떨어지는 자두는 없음
            } else {
                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0] + 1); // 2번 아래에 서 있는 경우
                if(j < w && j < t-1) // 방향을 바꿀 수 있는 상황에서
                    dp[i][j+1][0] = max(dp[i][j+1][0], dp[i-1][j][1]+1); // 1번으로 자리를 바꾸어 받아먹는 경우

                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1]); // 1번 나무에서 떨어지는 자두는 없음
            }
        }
    }

    for(int i=0; i<=w; i++){
        res = max(res, max(dp[t][i][0], dp[t][i][1])); // 최종 최댓값 계산
    }
    cout << res << '\n';
    return 0;
}