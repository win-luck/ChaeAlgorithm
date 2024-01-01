#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    long long tmp = 0;
    cin >> m >> n;
    for(long long i=0; i<n; i++){
        long long a;
        cin >> a;
        tmp += a;
        v.push_back(a);
    }

    long long l = 1;
    long long r = 1000000001;
    while(l <= r){
        long long mid = (l+r) / 2;
        long long cnt = 0;
        for(int i=0; i<n; i++){
            cnt += (v[i] / mid);
        }

        if(cnt >= m){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r;
    return 0;
}
