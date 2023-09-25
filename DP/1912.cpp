#include <iostream>
#include <algorithm>

using namespace std;
long long arr[100001];
long long dp[100001];
long long answer = 0;
int n;

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    fill(dp, dp+100001, 0);
    dp[1] = arr[1];
    answer = dp[1];
    for(int i=2; i<=n; i++){
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        answer = max(answer, dp[i]);
    }
    cout << answer;
    return 0;
}
