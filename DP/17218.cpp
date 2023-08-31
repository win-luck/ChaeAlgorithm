#include <iostream>
#include <algorithm>

using namespace std;
int dp[41][41];
string str1, str2, answer;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str1;
    cin >> str2;

    string a = " " + str1;
    string b = " " + str2;
    int n = a.size() - 1;
    int m = b.size() - 1;

    for(int i=1; i<a.size(); i++){
        for(int j=1; j<b.size(); j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }


    while(dp[n][m] != 0){ // 역추적
        if(dp[n][m] == dp[n][m-1]){ // 왼쪽으로 이동
            m--;
        } else if(dp[n][m] == dp[n-1][m]){ // 위로 이동
            n--;
        } else { // 대각선으로 이동
            answer += a[n];
            n--;
            m--;
        }
    }

    reverse(answer.begin(), answer.end());
    cout << answer;
    return 0;
}
