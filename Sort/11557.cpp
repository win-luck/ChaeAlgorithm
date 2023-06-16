#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string s;
vector<pair<string, int> > v;

bool cmp(pair<string, int> p1, pair<string, int> p2){
    return p1.second < p2.second;
}

int main(){
    int t, n;
    cin >> t;
    for(int a=0; a<t; a++){
        v.clear();
        cin >> n;
        for(int i=0; i<n; i++){
            int a;
            cin >> s >> a;
            v.push_back(make_pair(s, a));
        }
        sort(v.begin(), v.end(), cmp);
        cout << v.back().first << '\n';
    }
    return 0;
}