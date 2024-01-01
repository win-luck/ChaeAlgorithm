#include <iostream>
#include <vector>
#include <algorithm>

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

    for(int i=0; i<m; i++){
        long long s, e;
        cin >> s >> e;
        long long idx1 = lower_bound(v.begin(), v.end(), s) - v.begin();
        long long idx2 = upper_bound(v.begin(), v.end(), e) - v.begin();
        cout << idx2-idx1 << '\n';
    }
    return 0;
}
