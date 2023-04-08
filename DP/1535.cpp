#include <iostream>
#include <vector>

using namespace std;
int n;
int dp[21][101]; // N명의 사람까지 만날 수 있을 때 100의 체력으로 얻은 최대 점수
int power[21];
int please[21];
int m = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++){ // 잃을 체력
        cin >> power[i];
    }
    for(int i=1; i<=n; i++){ // 얻을 점수
        cin >> please[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=100; j>=0; j--){
            if(j-power[i]>=1){ // 경계값이 0이면 게임오버
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-power[i]] + please[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }

            m = max(m, dp[i][j]); // 최대 점수 갱신
        }
    }
    cout << m << '\n';
    return 0;
}