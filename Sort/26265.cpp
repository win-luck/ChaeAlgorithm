#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<string, string> > v;
int n;

bool cmp(pair<string, string> p1, pair<string, string> p2){
    if(p1.first == p2.first) return p1.second > p2.second;
    return p1.first < p2.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        string str1, str2;
        cin >> str1 >> str2;
        v.push_back(make_pair(str1, str2));
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<n; i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }
}
