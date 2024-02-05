#include <iostream>

using namespace std;
int dp[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 1->SK, -1->CY
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = -1;
    dp[3] = 1;
    dp[4] = 1;
    for(int i=5; i<=n; i++){
        if(dp[i-1] + dp[i-3] + dp[i-4] < 3){
            dp[i] = 1;
        } else {
            dp[i] = -1;
        }
    }
    cout << ((dp[n] == 1) ? "SK" : "CY");
    return 0;
}
