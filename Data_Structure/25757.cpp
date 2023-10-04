#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    char type;
    set<string> s;

    cin >> n;
    cin >> type;

    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        s.insert(str);
    }

    if(type == 'Y'){
        cout << s.size();
    } else if(type == 'F'){
        cout << s.size() / 2;
    } else {
        cout << s.size() / 3;
    }
    return 0;
}
