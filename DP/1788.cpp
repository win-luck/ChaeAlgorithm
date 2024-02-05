#include <iostream>
#include <algorithm>

using namespace std;
long long dp[1000001];
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=1000000; i++){
        dp[i] = (dp[i-1] % 1000000000) + (dp[i-2] % 1000000000);
        dp[i] %= 1000000000;
    }

    cin >> n;
    if(n == 0) cout << 0 << '\n';
    else if(n < 0 && abs(n) % 2 == 0) cout << -1 << '\n';
    else cout << 1 << '\n';
    cout << dp[abs(n)];

    return 0;
}
