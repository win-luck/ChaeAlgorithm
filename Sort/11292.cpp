#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<string, double> > v;
int n;

bool cmp(pair<string, double> p1, pair<string, double> p2){
    return p1.second > p2.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    while(1){
        cin >> n;
        v.clear();
        if(n == 0) break;
        for(int i=0; i<n; i++){
            string str;
            double a;
            cin >> str >> a;
            v.push_back(make_pair(str, a));
        }
        sort(v.begin(), v.end(), cmp);
        cout << v[0].first << " ";
        for(int i=1; i<n; i++){
            if(v[0].second == v[i].second){
                cout << v[i].first << " ";
            } else {
                break;
            }
        }
    }
    return 0;
}
