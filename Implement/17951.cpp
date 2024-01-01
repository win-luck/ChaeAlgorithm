#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, k;
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int total = 0;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        total += a;
        v.push_back(a);
    }

    if(k == 1){
        cout << total;
        return 0;
    }

    int l = 0;
    int r = total;
    int result = r;
    while(l <= r){
        int mid = (l+r) / 2;
        int sum = 0;
        int cnt = 0;
        for(int i=0; i<v.size(); i++){
            sum += v[i];
            if(sum > mid){
                cnt++;
                sum = 0;
            }
        }

        if(cnt >= k){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}
