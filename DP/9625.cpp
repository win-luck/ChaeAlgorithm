#include <iostream>


using namespace std;
int k;
pair<int, int> dp[46];

int main(){
    cin >> k;

    dp[1].first = 0; // A의 개수
    dp[1].second = 1; // B의 개수
    dp[2].first = 1;
    dp[2].second = 1;
    dp[3].first = 1;
    dp[3].second = 2;
    dp[4].first = 2;
    dp[4].second = 3;
    // 0 1 1 2
    // 1 1 2 3 피보나치
    
    for(int i=5; i<=k; i++){
        dp[i].first = dp[i-1].first + dp[i-2].first;
        dp[i].second = dp[i-1].second + dp[i-2].second;
    }
    cout << dp[k].first << " " << dp[k].second << '\n';
    return 0;
}