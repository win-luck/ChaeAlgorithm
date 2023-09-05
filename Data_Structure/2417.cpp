#include <iostream>
#include <cmath>
#include <algorithm>

#define ll unsigned long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    ll s = 0; // 초기 시작점: 0
    ll e = sqrt(9223372036854776000) + 1; // 초기 종료점: 2^63 + 1
    ll res = 1;

    cin >> n;
    if(n == 0){
        cout << 0;
    } else {
        while(s <= e){
            ll mid = (s + e) / 2;
            if(mid * mid < n){
                s = mid + 1;
            } else {
                e = mid - 1;
                res = mid;
            }
        }
        cout << res;
    }
    return 0;
}