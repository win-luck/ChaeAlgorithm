#include <iostream>
#include <map>
#include <vector>

using namespace std;
int n;
map<string, string> m;
vector<string> v;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        string str, state;
        cin >> str;
        cin >> state;
        m[str] = state;
    }

    for(auto it: m){
        if(it.second == "enter"){
            v.push_back(it.first);
        }
    }

    for(int i=v.size()-1; i>=0; i--){
        cout << v[i] << '\n';
    }
    return 0;
}