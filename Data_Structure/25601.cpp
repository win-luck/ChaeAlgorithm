#include <iostream>
#include <map>
#include <cmath>

using namespace std;
int n;
int val;
string str;
map<string, int> m;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str >> val;
        m[str] += val;
    }

    bool flag = false;
    for(auto it: m){
        for(auto it2: m){
            if(it.first != it2.first){
                if(floor(it.second * 1.618) == it2.second || it.second == floor(it2.second * 1.618)){
                    flag = true;
                    break;
                }
            }
        }
        if(flag) break;
    }
    if(flag){
        cout << "Delicious!";    
    } else {
        cout << "Not Delicious...";
    }
    return 0;
}
