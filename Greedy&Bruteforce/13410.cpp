#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, k;
    vector<int> v;

    cin >> n >> k;
    for(int i=1; i<=k; i++){
        string s = to_string(n * i);
        if(s.size() > 1){
            reverse(s.begin(), s.end());
        }
        v.push_back(stoi(s));
    }
    sort(v.begin(), v.end());
    cout << v.back();
    return 0;
}
