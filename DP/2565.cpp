#include <iostream>
#include <algorithm>

using namespace std;
pair<int, int> line[101];
int dp[101] = { 0, };

int main(){
    int n;
    int lis = 0;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> line[i].first >> line[i].second;
    }

    sort(line, line + n + 1);

    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = 1;
        for(int j=1; j<i; j++){
            if(line[i].second > line[j].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        lis = max(lis, dp[i]);
    }
    cout << n-lis << '\n';
    return 0;
}