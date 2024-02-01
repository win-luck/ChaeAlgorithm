#include <iostream>
#include <vector>

using namespace std;
long long n, t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        long long l = 1;
        long long r = 1000000001;
        long long exp = n * (n+1) / 2;
        while(l <= r){
            long long mid = (l+r) / 2;
            if(mid * (mid+1) <= exp){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << l << '\n';
    }
    return 0;
}
