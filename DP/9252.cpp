#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001][1001];

int main(){
    string str1, str2;
    cin >> str1 >> str2;

    string a = " " + str1; // 인덱스 초과를 막기위한 [0] 인덱스 쓰레기값 삽입
    string b = " " + str2;
    for(int i=1; i<a.size(); i++){
        for(int j=1; j<b.size(); j++){
            if(a[i] == b[j]){ // 두 문자가 같다면 그 직전 대각선에 해당하는 dp값에 +1 하면 됨
                dp[i][j] = dp[i-1][j-1] + 1;
            } else { // 만약 다르다면 그 옆이나 그 위의 값을 이어받게 됨.
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int n = a.size() - 1;
    int m = b.size() - 1;
    string answer = "";

    while(dp[n][m] != 0){
        if(dp[n][m] == dp[n][m-1]){ // 대각선이 1 차이나는 경우의 알파벳을 찾아내야 함. 이때 위나 왼쪽과 값이 같으면 안 됨.
            m--;
        } else if(dp[n][m] == dp[n-1][m]){
            n--;
        } else {
            answer += a[n];
            n--;
            m--;
        }
    }

    reverse(answer.begin(), answer.end());
    cout << dp[a.size()-1][b.size()-1] << endl;
    cout << answer;
    return 0;
}