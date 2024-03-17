#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    return 0;
}
