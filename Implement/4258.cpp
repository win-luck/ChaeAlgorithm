#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, t1, t2;
    vector<int> a;
    vector<int> b;
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0){
            return 0;
        }
        for(int i=0; i<n; i++){
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
        for(int i=0; i<m; i++){
            int tmp;
            cin >> tmp;
            b.push_back(tmp);
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            if(b[idx] == a[i]) cnt++;
        }
        cout << cnt << '\n';
        a.clear();
        b.clear();
    }
    return 0;
}
