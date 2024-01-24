#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int t, n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v(n, 0);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        int answer = v[1]-v[0];
        for(int i=0; i<n-2; i+=2){
            answer = max(v[i+2]-v[i], answer);
        }
        for(int i=1; i<n-2; i+=2){
            answer = max(v[i+2]-v[i], answer);
        }
        cout << answer << '\n';
    }
    return 0;
}
