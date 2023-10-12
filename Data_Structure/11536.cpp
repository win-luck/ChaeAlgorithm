#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2){
    return s1 > s2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string str;
    vector<string> v;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        v.push_back(str);
    }
    
    vector<string> tmp = v;
    if(tmp[0] < tmp[1]){
        sort(tmp.begin(), tmp.end());
    } else {
        sort(tmp.begin(), tmp.end(), cmp);
    }
    
    for(int i=0; i<n; i++){
        if(tmp[i] != v[i]){
            cout << "NEITHER";
            return 0;
        }
    }

    if(tmp[0] < tmp[1]){
        cout << "INCREASING";
    } else {
        cout << "DECREASING";
    }
    return 0;
}
