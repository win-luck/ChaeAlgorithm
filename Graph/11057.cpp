#include <iostream>

using namespace std;
int n;
int dp[1001][10] = { 0, }; // 오르막 수 개수

int main(){
    cin >> n;

    for(int i=0; i<10; i++){
        dp[1][i] = 1; // 자릿수 1인 경우는 무조건 1
    }

    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<=j; k++){
                dp[i][j] += dp[i-1][k]; // 자릿수 2인 경우에서 시작값이 j인 경우 -> 자릿수 1인 경우의 시작값이 0~j까지의 합
                dp[i][j] %= 10007;
            }
        }
    }

    int sum = 0;
    for(int i=0; i<10; i++){
        sum += dp[n][i];
    }
    cout << sum % 10007 << '\n';
    return 0;
}