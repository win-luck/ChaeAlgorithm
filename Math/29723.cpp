#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<string, int> p1, pair<string, int> p2){
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
} // 점수 오름차순

int main(){
    int n, t, k, a;
    string str;
    map<string, int> m;
    cin >> n >> t >> k;
    for(int i=0; i<n; i++){
        cin >> str >> a;
        m[str] = a;
    }
    
    int sum = 0;
    for(int i=0; i<k; i++){
        cin >> str;
        sum += m[str];
        m.erase(str);
    }

    vector<pair<string, int> > v(m.begin(), m.end());
    int minsum = sum;
    int maxsum = sum;

    sort(v.begin(), v.end(), cmp);
    int cnt = t-k;
    for(int i=0; i<cnt; i++){
        minsum += v[i].second;
        maxsum += v[v.size()-i-1].second;
    }
    cout << minsum << " " << maxsum;
    return 0;
}
