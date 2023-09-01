#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int dp[5001];
vector<int> v;
int n, k;

int recur(int idx){
    if(idx == n-1) return 1;
    if(dp[idx] != -1) return dp[idx]; // 메모이제이션

    dp[idx] = 0;
    for(int j=idx+1; j<n; j++){
        if((abs(v[j] - v[idx]) + 1) * (j-idx) <= k){
            if(recur(j) == 1){
                dp[idx] = 1;
                break;
            }
        }
    }
    return dp[idx];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    if(recur(0) == 1) cout << "YES";
    else cout << "NO";
    return 0;
}
