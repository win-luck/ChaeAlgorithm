#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool flag;

void check(string s1, string s2){
    for(int i=0; i<s1.size(); i++){
        if(find(s2.begin(), s2.end(), s1[i]) != s2.end()){
            int idx = s2.find(s1[i]);
            s2.erase(0, idx+1);
        } else {
            flag = false;
            break;
        }
    }
    if(flag) cout << "Yes\n";
    else cout << "No\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str1, str2;

    while(cin >> str1 >> str2){
        flag = true;
        check(str1, str2);
    }
    return 0;
}
