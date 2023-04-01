#include <iostream>

using namespace std;
int n;

bool isPrime(int n){ // 소수 판정
    if(n < 2) return false;
    for(int i=2; i*i<=n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void DFS(int val, int cnt){
    if(cnt == n){ // n자리 충족
        cout << val << '\n';
        return;
    }

    for(int i=1; i<10; i+=2){ // 자릿수 하나씩 늘려가며 모든 경우가 소수인지 검사
        if(isPrime(val*10 + i)){
            DFS(val*10 + i, cnt + 1);
        }
    }
}

int main(){
    cin >> n;
    // 첫 자리는 무조건 2, 3, 5, 7로 시작한다.
    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);
    return 0;
}