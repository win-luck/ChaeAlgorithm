#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
vector<long long> v;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for(int i=0; i<m; i++){
        long long a, b, c;
        cin >> a;
        if(a == 1){
            cin >> b;
            int idx = lower_bound(v.begin(), v.end(), b) - v.begin();
            cout << n-idx << '\n';
        } else if(a == 2){
            cin >> b;
            int idx = upper_bound(v.begin(), v.end(), b) - v.begin();
            cout << n-idx << '\n';
        } else {
            cin >> b >> c;
            int idx1 = upper_bound(v.begin(), v.end(), c) - v.begin(); 
            int idx2 = lower_bound(v.begin(), v.end(), b) - v.begin();  
            cout << idx1-idx2 << '\n';
        }
    }
    return 0;
}
