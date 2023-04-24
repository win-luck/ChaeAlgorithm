#include <iostream>
#include <map>

using namespace std;
map<string, bool> m;
int n;

int main(){
    int cnt = 0;
    string str;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        if(str == "ENTER") m.clear();
        else {
            if(m[str] == false) {
                m[str] = true; 
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}