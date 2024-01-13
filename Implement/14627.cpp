#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, c;
vector<long long> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    for(int i=0; i<n; i++){
        long long a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    long long l = 1;
    long long r = v.back();
    long long result = 0;
    long long tmp = 0;

    while(l <= r){
        long long mid = (l+r) / 2;
        long long cnt = 0;
        for(int i=0; i<n; i++){
            cnt += (v[i] / mid);
        }

        if(cnt >= c){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    // 최대 파의 길이 계산 완료

    bool flag = false;
    for(int i=0; i<n; i++){
        if(flag){
            result += v[i];
            continue;
        }

        while(v[i] >= r){
            if(tmp == c){
                result += v[i];
                flag = true;
                break;
            }
            if(v[i] >= r){
                v[i] -= r;
                tmp++;
            }
        }
        if(!flag)
            result += v[i];
    }
    cout << result;
    return 0;
}
