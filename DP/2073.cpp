#include <iostream>
#include <vector>

using namespace std;
int n, m, k, s;
int dp[12880]; // 메모리 초과를 막기위한 1차원 dp
int w[3402];
int d[3402];

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> w[i] >> d[i];
    } // 무게와 가치

    for(int i=0; i<n; i++){ // 최대 가치를 갖는 가방 찾기
        for(int j=m; j>=w[i]; j--){
            dp[j] = max(dp[j], dp[j-w[i]] + d[i]);
        }
    }
    cout << dp[m] << '\n';
    return 0;
}