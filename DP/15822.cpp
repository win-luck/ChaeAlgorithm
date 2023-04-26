#include <iostream>

using namespace std;
int n;
int X[2001], Y[2001];
int dp[2001][2001] = {0};

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> X[i];
    }
    for(int i=0; i<n; i++){
        cin >> Y[i];
    }

    dp[0][0] = abs(X[0] - Y[0])*abs(X[0]-Y[0]);
    for(int i=1; i<n; i++){
        dp[0][i] = dp[0][i-1] + abs(X[0] - Y[i])*abs(X[0] - Y[i]);
    }
    for(int i=1; i<n; i++){
        dp[i][0] = dp[i-1][0] + abs(X[i] - Y[0])*abs(X[i] - Y[0]);
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            dp[i][j] = abs(X[i]-Y[j]) * abs(X[i]-Y[j]) + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
    }

    cout << dp[n-1][n-1] << '\n';
    return 0;
}