#include <iostream>

using namespace std;
int n, k;
long long dp[31][31] = { 0, };

long long make(long long n, long long k){ // Top-Down
    if(k == 0 || k == n) return 1; // nC0과 nCn은 무조건 1
    if(k == 1) return n; // nC1은 무조건 n
    if(dp[n][k] == 0){ // 메모이제이션 안 된 상태라면 갱신
        dp[n][k] = make(n-1, k) + make(n-1, k-1);
    }
    return dp[n][k];
}

int main(){
    cin >> n >> k;
    cout << make(n-1, k-1);
    return 0;
}