#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, c;
vector<long long> v;

bool validcheck(long long mid){ // 모든 구간이 mid 이상인지 확인하는 과정
    long long tmp = v[0];
    long long cnt = 1;
    for(int i=1; i<v.size(); i++){
        if(v[i]-tmp >= mid){
            cnt++;
            tmp = v[i];
        }
    }
    return (cnt >= c);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    long long l = 0;
    long long r = v.back()-v[0];
    long long answer = 0;
    while(l <= r){
        long long mid = (l+r) / 2;
        if(validcheck(mid)){
            answer = max(answer, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << answer;
    return 0;
}
