#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int n, m;

bool validcheck(long long mid){
    int maxval = v[0];
    int minval = v[0];
    int cnt = 1; // 최초 구간은 1개

    for(int i=1; i<v.size(); i++){
        maxval = max(maxval, v[i]);
        minval = min(minval, v[i]);

        if(maxval - minval > mid){
            cnt++;
            maxval = v[i];
            minval = v[i];
        }
    }
    return (cnt <= m); // m개 이하의 구간
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    if(m == 1){
        cout << *max_element(v.begin(), v.end())  - *min_element(v.begin(), v.end());
        return 0;
    }

    long long l = 0;
    long long r = *max_element(v.begin(), v.end());
    long long result = r;
    while(l <= r){
        long long mid = (l+r) / 2;
        if(validcheck(mid)){ // mid 기반 m개 이하의 구간으로 성공적으로 나누었음
            r = mid - 1;
            result = min(result, mid);
        } else { // 구간이 너무 많음 -> mid를 키워야 함
            l = mid + 1;
        }
    }
    cout << result;
    return 0;
}
