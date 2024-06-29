#include <iostream>
#include <stack>

using namespace std;
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        stack<char> s;
        string str;
        int l;
        bool flag = true;

        cin >> l;
        cin >> str;
        for(int j=0; j<l; j++){
            if(str[j] == '>'){
                s.push(str[j]);
            } else {
                if(s.empty()) {
                    flag = false;
                    break;
                } else {
                    s.pop();
                }
            }
        }
        if(!s.empty()) flag = false;

        if(flag) cout << "legal\n";
        else cout << "illegal\n";
    }
    return 0;
}
