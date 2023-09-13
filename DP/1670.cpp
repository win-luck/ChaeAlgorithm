#include <iostream>

using namespace std;
int n;
long long dp[10001];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;
    fill(dp, dp + 10001, 0);
    dp[0] = 1;
    dp[2] = 1;
    dp[4] = 2;
    for(int i=6; i<=n; i+=2){
        for(int j=0; j<=i-2; j+=2){
            dp[i] += (dp[j] * dp[i-2-j]) % 987654321;
        }
        dp[i] %= 987654321;
    }
    cout << dp[n];
    return 0;
}
