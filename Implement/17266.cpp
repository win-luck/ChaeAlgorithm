#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int l = 0;
    int r = 100001;
    while(l <= r){
        int mid = (l+r) / 2;
        int cnt = 0;

        bool flag = true;
        int tmp = v[0];
        for(int i=1; i<v.size(); i++){
            if(v[i]-tmp <= 2*mid){
                tmp = v[i];
            } else {
                flag = false;
                break;
            }
        }
        if(v[0] > mid || n-v.back() > mid){
            flag = false;
        }

        if(!flag){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}
