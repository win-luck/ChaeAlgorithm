#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<long long> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long tmp = 0;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        long long a;
        cin >> a;
        if(a > tmp) 
            tmp = a;
        v.push_back(a);
    }

    long long l = tmp;
    long long r = 1000000001;
    while(l <= r){
        long long mid = (l+r) / 2;
        long long sum = 0;
        long long cnt = 0;

        for(int i=n-1; i>=0; i--){
            sum += v[i];
            if(sum > mid){
                cnt++;
                sum = v[i];
            }
        }

        if(cnt >= m){ // cnt가 크다 -> mid가 작다
            l = mid + 1;
        } else { // mid가 크다
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}
