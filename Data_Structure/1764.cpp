#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
map<string, bool> hear;
map<string, bool> see;
vector<string> v;

int main(){
    int n, m;
    cin >> n >> m;
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        hear[str] = true;
    }

    for(int i=0; i<m; i++){
        cin >> str;
        see[str] = true;
        if(hear[str] == true && see[str] == true){
            v.push_back(str);
        }
    }

    sort(v.begin(), v.end());
    
    cout << v.size() << '\n';
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }
    return 0;
}