#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
vector<long long> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        long long a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    long long l = 0;
    long long r = v.back() * m;
    while(l <= r){
        long long mid = (l+r) / 2;
        long long cnt = 0;
        for(int i=0; i<n; i++){
            cnt += (mid / v[i]);
        }

        if(cnt >= m){
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}
