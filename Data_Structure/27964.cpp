#include <iostream>
#include <map>

using namespace std;
int n;
map<string, bool> m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        if(str.size() <= 5) continue;
        if(str.substr(str.size()-6, 6) == "Cheese"){
            m[str] = true;
        }
    }
    if(m.size() >= 4){
        cout << "yummy";
    } else {
        cout << "sad";
    }
    return 0;
}