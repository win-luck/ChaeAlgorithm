#include <iostream>
#include <cstring>

using namespace std;
int n;
string str;
int dp[41];

int main(){
    
    cin >> str;
    dp[0] = 1;
    for(int i=1; i < str.size(); i++){
        if((str[i-1]-'0')*10 + (str[i]-'0') <= 34 && str[i-1] != '0') 
            dp[i] = (i == 1) ? 1 : dp[i-2];
        if(str[i] != '0')
            dp[i] += dp[i-1];
    }
    cout << dp[str.size()-1] << '\n';
    return 0;
}