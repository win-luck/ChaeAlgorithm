#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int cnt = 0;
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    v.resize(n, 0);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int s = 0, e = 1;
    while(s < e && e < n){
        if(v[s] + v[e] == m) cnt++;
        if(e == n-1){
            s++;
            e = s+1;
        } else {
            e++;
        }
    }
    cout << cnt;
    return 0;
}
