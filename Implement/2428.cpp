#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<double> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long cnt = 0;
    for(int i=0; i<n; i++){
        double val = 10 * v[i] / 9;
        int idx = upper_bound(v.begin()+i+1, v.end(), val) -(v.begin()+i+1);
        cnt += idx;
    }
    cout << cnt;
    return 0;
}
