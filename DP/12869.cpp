#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int n;
int scv[3];
int dp[61][61][61];

int attack(int a, int b, int c, int cnt){
    if(a <= 0 && b <= 0 && c <= 0) return cnt; // 다 잡았을 때
    if(a < 0) a = 0; // 음수는 0으로 표현
    if(b < 0) b = 0;
    if(c < 0) c = 0;

    if(dp[a][b][c] > 0) return dp[a][b][c]; // 메모이제이션

    int res = 987654321;
    if(a > 0){ // a가 공격받음
        res = min(res, attack(a-9, b-3, c-1, cnt+1));
        res = min(res, attack(a-9, b-1, c-3, cnt+1));
    }
    if(b > 0){ // b가 공격받음
        res = min(res, attack(a-1, b-9, c-3, cnt+1));
        res = min(res, attack(a-3, b-9, c-1, cnt+1));
    }
    if(c > 0){ // c가 공격받음
        res = min(res, attack(a-1, b-3, c-9, cnt+1));
        res = min(res, attack(a-3, b-1, c-9, cnt+1));
    }

    dp[a][b][c] = res;
    return res;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> scv[i];
    }

    memset(dp, 0, sizeof(dp));
    cout << attack(scv[0], scv[1], scv[2], 0) << '\n';
    return 0;
}