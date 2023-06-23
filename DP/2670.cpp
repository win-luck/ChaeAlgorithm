#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<double> v;
double dp[10001] = {0.0,};
double res = 0.0;

int main(){

    cin >> n;
    for(int i=1; i<=n; i++){
        double a;
        cin >> a;
        v.push_back(a);
    }

    dp[0] = v[0];    
    for(int i=1; i<n; i++){
        dp[i] = max(v[i], dp[i-1]*v[i]);
        res = max(res, dp[i]);
    }
    cout.precision(3);
    cout << fixed;
    cout << res << '\n';
    return 0;
}