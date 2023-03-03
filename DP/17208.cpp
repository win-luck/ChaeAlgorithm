#include <iostream>

using namespace std;
int n, m, k, x, y;
int dp[101][301][301] = { 0, }; // n개의 주문, m개의 버거, k개의 감자튀김 중 "가장 많이 받을 수 있는 주문의 개수"
int b[301];
int p[301];

void input(){
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        cin  >> b[i] >> p[i];
    }
} // 입력

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    input();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int a=1; a<=k; a++){
                if(b[i] <= j && p[i] <= a) // 햄버거와 감자튀김 모두 여유가 된다면
                    dp[i][j][a] = max(dp[i-1][j][a], dp[i-1][j-b[i]][a-p[i]] + 1); // 배낭 문제 적용
                else
                    dp[i][j][a] = dp[i-1][j][a]; // 그렇지 않다면 직전 값 계승
            }
        }
    }

    cout << dp[n][m][k] << '\n';
    return 0;
}