#include <iostream>

using namespace std;

long long dp[41];

long long fibo(int N){
    if(N == 0 || N == 1){
        return dp[N];
    } else if(dp[N] == 0) {
        dp[N] = fibo(N-1) + fibo(N-2);
    }
    return dp[N];
}

int main(){
    int n, t;
    cin >> t;
    dp[0] = 0;
    dp[1] = 1;
    for(int i=0; i<t; i++){
        cin >> n;
        if(n == 0) cout << "1 0 " << '\n';
        else cout << fibo(n-1) << " " << fibo(n) << '\n';
    }

    return 0;
}