#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int x, y;
    double tmp, z;
    cin >> x >> y;
    z = (double)y*100/x;
    if(z >= 99){ // 초기 승률이 99퍼면 절대 100퍼센트가 될 수 없음
        cout << -1;
        return 0;
    }

    int l = 0, r = x;
    int result = -1;
    while(l <= r){
        int mid = (l+r) / 2;
        int nx = x + mid;
        int ny = y + mid;
        int nz = ((double)ny*100/nx);
        if(nz > z){
            r = mid-1;
            result = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << result;
    return 0;
}
