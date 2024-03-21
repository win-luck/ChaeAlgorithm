#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<string> v;

bool cmp(string a, string b){
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        string tmp = "";
        for(int j=0; j<str.size(); j++){
            if(str[j] >= '0' && str[j] <= '9'){
                tmp += str[j];
            } else {
                if(!tmp.empty()){
                    while(tmp.size() >= 2 && tmp[0] == '0'){
                        tmp.erase(tmp.begin());
                    }
                    v.push_back(tmp);
                    tmp = "";
                }
            }
        }
        if(!tmp.empty()){
            while(tmp.size() >= 2 && tmp[0] == '0'){
                tmp.erase(tmp.begin());
            }
            v.push_back(tmp);
            tmp = "";
        }
    }

    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }
    return 0;
}
