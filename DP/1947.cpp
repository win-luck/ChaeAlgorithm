#include <iostream>
#include <algorithm>

using namespace std;
int n;
long long dp[1000001];

int main(){
    cin >> n;
    dp[1] = 0; // 자기 자신이 선물 받는 경우 없으니까 0
    dp[2] = 1; // 상대에게 주는 경우 1
    dp[3] = 2; // 첫번째 사람이 정하는 그 순간 경우가 결정되므로 두 사람 중 하나 선택하는 1
    dp[4] = 9; // 
    dp[5] = 44; // dp[k] = (dp[k-1]+dp[k-2]) * (k-1)
    for(int i=6; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) * (i-1) % 1000000000;
    }
    cout << dp[n];
    return 0;
}