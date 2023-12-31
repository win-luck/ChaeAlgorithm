#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, n, m, a, result;
vector<int> A;
vector<int> B;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> a;
            A.push_back(a);
        }
        sort(A.begin(), A.end());
        for(int i=0; i<m; i++){
            cin >> a;
            B.push_back(a);
        }
        sort(B.begin(), B.end());
        for(int i=0; i<n; i++){
            int idx = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
            result += idx;
        }
        cout << result << '\n';
        result = 0;
        A.clear();
        B.clear();
    }
    return 0;
}
