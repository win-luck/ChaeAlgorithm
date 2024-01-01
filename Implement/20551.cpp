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
    cin >> n >> m;
    for(long long i=0; i<n; i++){
        long long a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    for(long long i=0; i<m; i++){
        long long d;
        cin >> d;
        long long idx = lower_bound(v.begin(), v.end(), d) - v.begin();
        if(v[idx] != d || idx >= n) {
            cout << -1 << '\n';
        } else {
            cout << idx << '\n';
        }
    }
    return 0;
}
