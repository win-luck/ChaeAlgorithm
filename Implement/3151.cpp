#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;
    for(long long i=0; i<n; i++){
        long long a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    long long result = 0;
    for(int i=0; i<=n-3; i++){
        long long l = i+1;
        long long r = n-1;
        while(l < r){
            if(v[i] + v[l] + v[r] == 0){
                if(v[l] == v[r]){ // l~r이 동일한 숫자인 경우
                    result += r-l;
                    l++;
                } else { // l과 r이 서로 다른 숫자인 경우
                    int lcnt = 0;
                    int rcnt = 0;
                    int left = v[l];
                    int right = v[r];

                    while(left == v[l]){
                        l++;
                        lcnt++;
                    }

                    while(right == v[r]){
                        r--;
                        rcnt++;
                    }

                    result += (lcnt * rcnt);
                }
            } else if(v[i] + v[l] + v[r] > 0){
                r--;
            } else {
                l++;
            }
        }
    }
    cout << result;
    return 0;
}
