#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int sum = 0;
    for(int i=0; i<n; i++){
        if((i+1) % 3 == 0) continue;
        sum += v[i];
    }
    cout << sum;
    return 0;
}
