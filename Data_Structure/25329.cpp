#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
int n;
map<string, int> m;

bool cmp(pair<string, int> p1, pair<string, int> p2){
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}

int getTax(int time){
    int val = 10;
    if(time <= 100){
        return val;
    } 
    time -= 100;
    while(time > 0){
        time -= 50;
        val += 3;
    }
    return val; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        string str1, str2;
        cin >> str1 >> str2;
        int hour = stoi(str1.substr(0, 2));
        int minute = stoi(str1.substr(3, 2));
        m[str2] += hour*60 + minute;
    }
    vector<pair<string, int> > v;
    for(auto it: m){
        int tax = getTax(it.second);
        v.push_back(make_pair(it.first, tax));
    }
    sort(v.begin(), v.end(), cmp);
    for(auto it: v){
        cout << it.first << " " << it.second << '\n';
    }
    return 0;
}
