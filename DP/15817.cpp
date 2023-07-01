#include <iostream>

using namespace std;
int n, x;
int dp[10001];
int L[101];
int C[101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    dp[0] = 1;
    for(int a=1; a<=n; a++){
        cin >> L[a] >> C[a]; // 입력
        for(int i=x; i>0; i--){ // 탑다운으로 내려가야 중복이 없다.
            int p = 0; // 4 3이 들어오면, p는 차례대로 4, 8, 12가 된다.
            for(int j=0; j<C[a]; j++){ // 여기서 4, 8, 12를 만드는 경우의 수가 dp[0]을 통해 갱신된다.
                p += L[a];
                if(i-p < 0) break;
                else dp[i] += dp[i-p];
            }
        }
    }
    cout << dp[x] << '\n';
    return 0;
}