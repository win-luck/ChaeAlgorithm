#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define INF 10001
using namespace std;
int n, k;
int dp[10001];// n개의 동전으로 k원을 만든다
vector<int> money;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[0] = 0;
    for(int i=1; i<=k; i++){
        dp[i] = INF;
    }

    cin >> n >> k;    
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        money.push_back(a);
    }
    sort(money.begin(), money.end()); // 동전 정렬

    for(int i=0; i<n; i++){
        for(int j=money[i]; j<=k; j++){
            dp[j] = min(dp[j], dp[j - money[i]] + 1); // 15원을 만드는 경우 = 15원 or 10원 + 5원의 경우
        }
    }

    if(dp[k] == INF)
        cout << -1;
    else
        cout << dp[k];
    return 0;
}