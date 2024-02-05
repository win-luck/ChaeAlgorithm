#include <iostream>
#include <algorithm>

using namespace std;
int dp[2001];
int arr[2001];
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    dp[1] = 1;
    int cnt = dp[1];
    for(int i=2; i<=n; i++){
        int val = 0;
        for(int j=1; j<i; j++){
            if(arr[j] > arr[i]){
                val = max(val, dp[j]);
            }
        }
        dp[i] = val + 1;
        cnt = max(cnt, dp[i]);
    }
    cout << n-cnt;
    return 0;
}
