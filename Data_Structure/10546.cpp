#include <iostream>
#include <map>

using namespace std;
int n;
string str;
map<string, bool> m;

int main(){
    cin >> n;
    for(int i=0; i<2*n-1; i++){
        cin >> str;
        m[str] = !m[str];
    }

    for(auto it: m){
        if(it.second == true){
            cout << it.first << '\n';
            break;
        }
    }
    return 0;
}