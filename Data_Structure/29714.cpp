#include <iostream>
#include <map>
#include <vector>

using namespace std;
map<int, int> m;
int n, k;
int a, b;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        m[a]++;
    }
    cin >> k;
    for(int i=0; i<k; i++){
        vector<int> v;
        cin >> a;
        map<int, int> tmpm;
        for(int j=0; j<a; j++){
            int tmp;
            cin >> tmp;
            tmpm[tmp]++;
        }
        bool flag = true;
        if(!tmpm.empty()){
            for(auto it: tmpm){
                if(m.count(it.first) > 0){
                    if(m[it.first] < it.second){
                        flag = false;
                        break;
                    }
                } else {
                    flag = false;
                }
            }
            if(flag){
                for(auto it: tmpm){
                    if(m.count(it.first) > 0){
                        m[it.first] -= it.second;
                    }
                }
            }
        }

        cin >> a;
        for(int j=0; j<a; j++){
            int tmp;
            cin >> tmp;
            if(flag)
                m[tmp]++;
        }
    }
    int cnt = 0;
    for(auto it: m){
        cnt += it.second;
    }
    cout << cnt << '\n';
    if(cnt != 0){
        for(auto it: m){
            for(int j=0; j<it.second; j++){
                cout << it.first << " ";
            }
        }
    }
    return 0;
}
