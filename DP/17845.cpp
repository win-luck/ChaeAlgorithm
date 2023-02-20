#include <iostream>
#include <vector>

using namespace std;
long long dp[1001][10001]; // 과목 수, 최대 공부시간

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<long long, long long> > vlist;

    for(int i=0; i<k; i++){
        long long im, t;
        cin >> im >> t;
        vlist.push_back(make_pair(im, t));
    }

    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            int curval = vlist[i-1].first;
            int curtime = vlist[i-1].second;

            if(curtime <= j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-curtime] + curval);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[k][n] << '\n';
    return 0;
}