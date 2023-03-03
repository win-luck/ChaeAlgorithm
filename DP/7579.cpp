#include <iostream>

using namespace std;
int mem[101] = { 0, }; // 메모리
int c[101] = { 0, }; // 비용
int dp[101][10001] = { 0, }; // a개의 앱 중 b만큼의 비용을 비활성화했을 때의 "총 메모리"
int n, m;
int result = 10000001; // 일단 최대로 고정


void input(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> mem[i];
    }
    for(int i=1; i<=n; i++){
        cin >> c[i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    for(int i=1; i<=n; i++){
        for(int j=0; j<10001; j++){ // 비용의 합 최대는 10000이다.
            if(c[i] <= j)   { // 최대 j원까지 비용을 투자하여 얻을 수 있는 최대 메모리를 계산한다.
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - c[i]] + mem[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }

            if(dp[i][j] >= m) // m 이상의 메모리를 얻는 최소 j 비용 계산
                result = min(result, j);
        }
    }

    cout << result << '\n';
    return 0;
}