#include <iostream>

using namespace std;
int n;
int answer = 0;
int dp[1500001] = {0, }; // dp값: n-1일까지 상담했을 때 최대 이익
int arr[1500001][2]; // 시간과 이익

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i][0] >> arr[i][1]; // 1일의 시간과 이익
    }

    dp[1] = 0;
    for(int i=1; i<=n+1; i++){
        answer = max(answer, dp[i]);
        if(i + arr[i][0] > n+1) continue;
        dp[i + arr[i][0]] = max(dp[i + arr[i][0]], answer + arr[i][1]);
    }

    cout << answer << '\n';
    return 0;
}