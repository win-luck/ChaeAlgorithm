#include <iostream>
#include <cstring>

using namespace std;
long long dp[31][61]; // 한조각 알약, 반조각 알약
int n;

long long Drug(int one, int half){ // Top-Down 방식도 할 줄 알아야 한다는 교훈을 주는 문제.
    if(one == 0) return 1; // 한조각 알약이 없으면 무조건 반조각을 먹어야 한다. Top-Down의 바닥 조건이다.

    long long &val = dp[one][half];
    if(val != -1) return val; // 이미 메모이제이션 되어있다면 그대로 반환
    val = 0;

    if(one > 0){ // 알약 깨도 되면 깨기
        val += Drug(one - 1, half + 1);
    }
    if(half > 0){ // 반조각 먹을 수 있으면 먹기
        val += Drug(one, half - 1);
    }
    return val;
}

int main(){
    while(1){
        cin >> n;
        if(n == 0) break;
        memset(dp, -1, sizeof(dp)); // 메모이제이션 처리 유무 파악을 위해 -1로 초기화
        cout << Drug(n-1, 1) << '\n';
    }
    return 0;
}
/** 일단 맨 처음 하나의 알약은 반으로 깨야한다.
 * 또한 모든 알약이 다 깨지면 반토막난 알약만 먹을 수 있다,
 * Top-Down 약해질 때 또 풀어보기
*/ 