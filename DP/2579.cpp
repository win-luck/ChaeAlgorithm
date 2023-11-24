#include <iostream>

using namespace std;
int arr[301];
int dp[301];
int n;

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    // 연속된 3개 계단을 밟을 수 없음
    // 마지막 계단은 반드시 밟아야 함 (점화식에서 현재 포지션을 반드시 포함해야 함)
    for(int i=3; i<=n; i++){
        dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]);
    }
    cout << dp[n];
    return 0;
}
