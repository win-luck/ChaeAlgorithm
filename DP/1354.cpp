#include <iostream>
#include <map>

using namespace std;
long long n, p, q, x, y;
map<long long, long long> m; // 탐색범위가 지나치게 크므로 map으로 처리

long long recur(long long n){ // 메모이제이션 활용
    if(n <= 0) return 1;
    if(m.count(n) > 0){ // 이미 존재하면 반환
        return m[n];
    }
    if(n/p - x == n/q - y){ // 둘이 동일하면 계산 두 번 할 필요 없게
        return m[n] = 2 * recur(n/p - x);
    }
    return m[n] = recur(n/p - x) + recur(n/q - y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> p >> q >> x >> y;
    cout << recur(n) << '\n';
    return 0;
}