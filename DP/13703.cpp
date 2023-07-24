#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
long long k, n;
long long S = 0;
long long dp[64][64]; // 벼룩이 n초후 생존하는 경우의 수
// 수면에 닿으면 소멸한다.

long long recur(long long k, long long n){
    if(dp[k][n] != 0) return dp[k][n];
    if(k > n) return dp[k][n] = 0;
    if(k == 0) return dp[k][n] = (2LL << (n-1));
    if(n == k) return dp[k][n] = 1; // 똑같으면 단 하나의 경우 
    return dp[k][n] = recur(k-1, n-1) + recur(k+1, n-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp, 0, sizeof(dp));

    cin >> k >> n;
    recur(k, n);
    cout << (2LL << (n-1)) - dp[k][n];
    return 0;
}