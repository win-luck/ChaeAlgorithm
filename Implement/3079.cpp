#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
vector<unsigned long long> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        unsigned long long a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    unsigned long long l = 0;
    unsigned long long r = v.back() * m;
    while(l <= r){
        unsigned long long mid = (l+r) / 2;
        unsigned long long cnt = 0;
        for(int i=0; i<n; i++){
            cnt += (mid/v[i]);
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
