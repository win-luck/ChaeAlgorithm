#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
long long x, y;
vector<pair<long long, long long> > v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        long long a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());

    long long sum = 0;
    long long l = v[0].first;
    long long r = v[0].second;
    if(n == 1) {
        cout << r-l;
        return 0;
    }
    for(int i=1; i<n; i++){
        if(r < v[i].first) {// 현재의 끝이 다음의 시작보다 작음
            sum += r-l;
            l = v[i].first;
            r = v[i].second;
        } else { // 현재의 끝이 다음의 시작보다 크거나 같음
            if(r < v[i].second)
                r = v[i].second;
        }
    }
    sum += r-l;
    cout << sum;
    return 0;
}
