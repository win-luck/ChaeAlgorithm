#include <iostream>
#include <map>

using namespace std;
map<int, bool> m;
int a, b;
int input;
int cnt = 0;

int main(){
    cin >> a >> b;
    for(int i=0; i<a; i++){
        cin >> input;
        m[input] = !m[input];
    }
    for(int i=0; i<b; i++){
        cin >> input;
        m[input] = !m[input];
    }

    for(auto i: m){
        if(i.second == true){
            cnt++;
        }
    }
    cout << cnt << '\n';
}