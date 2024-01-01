#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, k;
    cin >> n >> k;
    for(long long i=0; i<n; i++){
        long long a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    long long l = v.front();
    long long r = v.back() + k;
    while(l <= r){
        long long mid = (l+r) / 2;
        long long cnt = 0;
        for(int i=0; i<n; i++){
            if(mid > v[i])
                cnt += (mid-v[i]);
        }

        if(cnt > k){ // 초과 -> mid를 줄여야 함
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << r;
    return 0;
}
