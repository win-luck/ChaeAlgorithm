#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, limit, sum = 0;
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
        sum += a;
    }
    sort(v.begin(), v.end());
    cin >> limit;
    if(sum <= limit){
        cout << v.back();
        return 0;
    }

    int l = 1;
    int r = v.back();
    while(l <= r){
        int mid = (l+r)/2;
        int tmpsum = 0;
        for(int i=0; i<v.size(); i++){
            if(mid >= v[i]){
                tmpsum += v[i];
            } else {
                tmpsum += mid;
            }
        }
        if(tmpsum > limit){ // 초과
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout << r;
    return 0;
}
