#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2){
    if(p1.first == p2.first){
        return p1.second.first < p2.second.first;
    }
    return p1.first < p2.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<pair<int, pair<int, int> > > v;
    for(int i=1; i<=150; i++){
        for(int j=i+1; j<=150; j++){
            v.push_back(make_pair(i*i+j*j, make_pair(i, j)));
        }
    }
    sort(v.begin(), v.end(), cmp);
    while(1){
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        int val = a*a + b*b;
        for(auto it: v){
            if(it.first == val){
                if(a >= it.second.first) continue;
                cout << it.second.first << " " << it.second.second << '\n';
                break;
            } else if(it.first > val){
                cout << it.second.first << " " << it.second.second << '\n';
                break;
            }
        }
    }
    return 0;
}
