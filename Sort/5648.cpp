#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<long long> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        v.push_back(stoll(str));
    }
    sort(v.begin(), v.end());
    for(auto it: v){
        cout << it << '\n';
    }
    return 0;
}
