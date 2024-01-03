#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long arr[1001][1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    long long tmp = 0;
    long long sum = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            long long a;
            cin >> a;
            arr[i][j] = a;
            tmp = max(tmp, a);
            sum += a;
        }
    }

    long long l = 0;
    long long r = tmp;
    while(l <= r){
        long long mid = (l+r) / 2;
        long long cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j] <= mid){
                    cnt += arr[i][j];
                } else {
                    cnt += mid;
                }
            }
        }
        long long limit = (sum % 2 == 0) ? (sum/2) : (sum/2 + 1);
        if(cnt >= limit){
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}
