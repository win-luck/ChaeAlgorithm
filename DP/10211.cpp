#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v;

        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            v.push_back(a);
        }

        int now = 0;
        int maxval = -999999999;
        for(int i=0; i<n; i++){
            now = v[i] + max(now, 0); // 앞 결과가 음수면 버린다.
            maxval = max(now, maxval);
        }
        cout << maxval << '\n';
    }
    return 0;
}
