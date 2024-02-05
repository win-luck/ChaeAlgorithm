#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    long long dp[65][10];

    for(int i=0; i<=9; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=64; i++){
        long long sum = 0;
        for(int j=0; j<=9; j++){
            dp[i][j] = dp[i-1][j] + sum;
            sum += dp[i-1][j];
        }
    }

    cin >> t;
    while(t--){
        cin >> n;
        long long sum = 0;
        for(int i=0; i<=9; i++){
            sum += dp[n][i];
        }
        cout << sum << '\n';
    }
    return 0;
}
