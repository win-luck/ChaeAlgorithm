#include <iostream>

#define INF 1000000
using namespace std;
int t, n, m;
int a, b, c;
int dp[301][301];

void Floyd(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int cnt = max(dp[i][k], dp[k][j]); // i -> j로 향하는 간선 중 최댓값 계산
                dp[i][j] = min(dp[i][j], cnt); // 그 중 최솟값을 저장
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> t;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        dp[a][b] = c;
    }

    Floyd();
    for(int i=0; i<t; i++){
        cin >> a >> b;
        if(dp[a][b] >= INF){
            cout << -1 << '\n';
        } else {
            cout << dp[a][b] << '\n';
        }
    }
    return 0;
}