#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    long long tmp = 0;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a;
        cin >> a;
        tmp += a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    long long l = 1;
    long long r = v.back();
    while(l <= r){
        long long mid = (l+r) / 2;
        long long cnt = 0;
        for(int i=0; i<m; i++){
            cnt += (v[i] / mid);
            if(v[i] % mid != 0) cnt++;
        }

        if(cnt <= n){
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}
