#include <iostream>

using namespace std;
long long dp[91];
int n;

int main(){
    // 이친수는 0으로 시작하지 않고, 1이 두 번 연속으로 나타나지 않는다.
    /**
     * 1자리 - 1
     * 2자리 - 10
     * 
     * 3자리 - 100, 101 -> 2
     * : 2자리 첫번째 수에서 0/1 추가
     * 
     * 4자리 - 1000, 1001, 1010 -> 3
     * : 3자리 0으로 끝나는 수에서 0/1 추가, 1로 끝나는 수에서 0 추가
     * 
     * 5자리 - 10001, 10010, 10100, 10101, 10000 -> 5
     * : 4자리 0으로 끝나는 수에서 0/1 추가, 1로 끝나는 수에서 0 추가
     * 
     * 6자리 - 100010, 101010, 100100, 100101, 101000, 101001, 100001, 100000 -> 8
     * : 5자리 0으로 끝나는 수에서 0/1 추가, 1로 끝나는 수에서 0 추가
     * 
     * 7자리 - 1001010, 1010010, 1000010 그리고 10 -> 13
    */

    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

   cout << dp[n];
}