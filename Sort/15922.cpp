#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<pair<long long, long long> > v;
long long answer = 0;

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

    long long l = v[0].first;
    long long r = v[0].second;
    for(int i=1; i<n; i++){
        if(r < v[i].first){
            answer += r-l;
            l = v[i].first;
            r = v[i].second;
        } else {
            if(r < v[i].second)
                r = v[i].second;
        }
    }
    answer += r-l;
    cout << answer;
    return 0;
}
