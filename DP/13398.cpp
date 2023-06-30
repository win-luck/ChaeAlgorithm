#include <iostream>

using namespace std;
int n;
int dp[100001][2];
int arr[100001];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    dp[0][0] = arr[0];
    dp[0][1] = arr[0];
    int res = arr[0];
    for(int i=1; i<n; i++){
        dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]); // i개짜리의 수열 중 연속합의 최대
        dp[i][1] = max(dp[i-1][0], dp[i-1][1] + arr[i]); // i개짜리의 수열 중 하나를 배제한 연속합의 최대
        res = max(res, max(dp[i][0], dp[i][1])); // dp[n-1]이 최대하고 볼 수 없으므로 매 반복문마다 초기화
    }
    cout << res;
    return 0;
}