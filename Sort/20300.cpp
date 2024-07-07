#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<long long> v;

int main()
{
    ios::sync_with(stdio);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    long long maxval = 0;
    if(v.size() % 2 == 1){
        maxval = v[n-1];
        n--;
    }
    for(int i=0; i<n/2; i++){
        long long a = v[i] + v[n-1-i];
        maxval = max(maxval, a);
    }
    cout << maxval;
    return 0;
}
