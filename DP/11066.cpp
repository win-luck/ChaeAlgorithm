#include <iostream>
#include <cstring>
#include <algorithm>

#define INF 987654321;
using namespace std;
int n;
int dp[501][501];
int p[501];
int sum[501];

int chainsum(int i, int j){
    if(i == j) return p[i]; // 단일 페이지
    if(dp[i][j] != -1) return dp[i][j]; // 이미 처리된 값이면 바로 반환
    dp[i][j] = INF; // INF로 초기화

    for(int k=i; k<j; k++){
        dp[i][j] = min(dp[i][j], chainsum(i, k) + chainsum(k+1, j)); // chain matrix와 유사
    }
    dp[i][j] += sum[j] - sum[i-1]; // 병합한 페이지만큼 추가
    return dp[i][j];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        memset(dp, -1, sizeof(dp));
        memset(sum, 0, sizeof(sum)); // 테케마다 초기화

        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> p[i];
            sum[i] = sum[i-1] + p[i];
        }

        cout << chainsum(1, n) - sum[n] << '\n'; // 실제로 병합에 사용된 비용만을 구하기 위함
    }
    return 0;
}