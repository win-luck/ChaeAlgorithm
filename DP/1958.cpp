#include <iostream>
#include <algorithm>

using namespace std;
int dp[101][101][101];

int main(){
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;

    string a = " " + str1; // 인덱스 초과를 막기위한 [0] 인덱스 쓰레기값 삽입
    string b = " " + str2;
    string c = " " + str3;
    for(int i=1; i<a.size(); i++){
        for(int j=1; j<b.size(); j++){
            for(int k=1; k<c.size(); k++){            
                if(a[i] == b[j] && b[j] == c[k]){ // 두 문자가 같다면 그 직전 대각선에 해당하는 dp값에 +1 하면 됨
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                } else { // 만약 다르다면 그 옆이나 그 위의 값을 이어받게 됨.
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                }
            }
        }
    }
    cout << dp[a.size()-1][b.size()-1][c.size()-1];
    return 0;
}