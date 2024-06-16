#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
int r, c;
vector<string> tmp;
vector<string> v;

bool validcheck(int idx){
    set<string> s;
    for(auto it: v){
        s.insert(it.substr(idx));
    }
    return s.size() == v.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    for(int i=0; i<r; i++){
        string str;
        cin >> str;
        tmp.push_back(str);
    }
    reverse(v.begin(), v.end());
    for(int i=0; i<c; i++){
        string now = "";
        for(int j=0; j<r; j++){
            now += tmp[j][i];
        }
        v.push_back(now);
    }

    int s = 0;
    int e = v.size()-1;
    while(s <= e){
        int mid = (s+e) / 2;
        if(validcheck(mid)){
            s = mid+1;
        } else {
            e = mid-1;
        }
    }
    cout << e;
    return 0;
}
