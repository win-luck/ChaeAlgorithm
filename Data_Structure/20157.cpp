#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
int n;
map<pair<int, int>, int> m;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        int a, b;
        cin >> a >> b;
        int d = gcd(a, b);
        if(d < 0) d = -d;
        m[make_pair(b/d, a/d)]++;
    }

    int cnt = 0;
    for(auto it: m){
        cnt = max(cnt, it.second);
    }
    cout << cnt;
    return 0;
}
