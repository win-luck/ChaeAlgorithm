#include <iostream>
#include <algorithm>

using namespace std;
int n, Max, Min;
int arr[1001];
int dp[1001] = {0,};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    // 연속된 학생들로 조를 구성한다.
    dp[0] = 0;
    dp[1] = 0; // 1명짜리 조는 무조건 0이다.
    dp[2] = abs(arr[2] - arr[1]); // 2명짜리 조는 무조건 서로의 차이다.
    
    for(int i=3; i<=n; i++){
        Max = arr[i];
        Min = arr[i]; // 오른쪽 끝에서 Max와 Min을 설정하고, 한칸씩 왼쪽으로 이동하면서 Max와 Min을 갱신한다.

        for(int j=i-1; j>=1; j--){
            Max = max(Max, arr[j+1]); // 이때 Max와 Min은 dp[j]에 해당하는 구간 안에 있으면 안 되기에 j+1
            Min = min(Min, arr[j+1]);
            dp[i] = max(dp[i], dp[j] + Max-Min); // 최댓값 갱신
        }
    }
    cout << dp[n] << '\n';
    return 0;
}