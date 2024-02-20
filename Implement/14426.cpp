#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<string> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        string a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int cnt = 0;
    for(int i=0; i<m; i++){
        string a;
        cin >> a;
        int s = a.size();
        int idx = lower_bound(v.begin(), v.end(), a) - v.begin();
        if(v[idx].substr(0, s) == a){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
