#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    vector<string> v;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end());
    cout << v[m-1];
    return 0;    
}
