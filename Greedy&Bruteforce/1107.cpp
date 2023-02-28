#include <iostream>
#include <cmath>

using namespace std;
int n, answer, target, tmp;
bool c[10];

int validcheck(int n){
    int cnt = 0;
    if(n == 0){
        if(c[n] == 0) return -1;
        return 1;
    } else if(n > 0){
        while(n > 0){
            if(c[n % 10] == 0) return -1; // 불가능한 숫자
            n /= 10; // 자릿수 추가
            cnt++;
        }
    }
    return cnt; // cnt번 눌러야 함을 알림
}

void solve(){
    answer = 500000; // 최대로 누르는 개수
    int len = 0;
    for(int i=0; i<=1000000; i++){ // 브루트포스
        len = validcheck(i);
        if(len == -1) continue;

        answer = min(answer, len + abs(target - i)); // abs는 + 혹은 -의 개수, cnt번과 결합하여 총 버튼 누르는 횟수 계산
    }
    answer = min(answer, abs(target - 100)); // 애초에 버튼 누를 필요 없이 목표가 100이면?
}

int main(){
    cin >> target >> n;

    for(int i=0; i<10; i++){
        c[i] = 1; 
    }

    for(int i=0; i<n; i++){
        cin >> tmp;
        c[tmp] = 0; // 사용 불가 처리
    }

    solve();
    cout << answer << '\n';
    return 0;
}