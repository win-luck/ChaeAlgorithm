#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;
int n;
map<string, bool> m;
vector<string> v;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }
    
    for(int i=1; i<100; i++){
        bool flag = false;
        for(int j=0; j<v.size(); j++){
            string tmp = v[j].substr(v[j].size() - i, i);
            if(m[tmp] == true){
                m.clear();
                flag = true;
                break;
            } else {
                m[tmp] = true;
            }
        }
        if(flag) {
            continue;
        } else {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}