#include <iostream>
#include <vector>

using namespace std;

bool isMo(char a){
    return (a == 'a' || a == 'i' || a == 'e' || a == 'o' || a == 'u');
}

bool validcheck(string str){
    bool flag = false;
    int cnt1 = 0;
    int cnt2 = 0;

    for(int i=0; i<str.size(); i++){
        if(isMo(str[i])){
            cnt1++;
            cnt2 = 0;
            flag = true;
        } else {
            cnt2++;
            cnt1 = 0;
        }

        if(cnt1 == 3 || cnt2 == 3){
            return false;
        }

        if(i > 0 && (str[i-1] == str[i]) && str[i] != 'e' && str[i] != 'o'){
            return false;
        }
    }
    if(!flag){
        return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    while(1){
        cin >> str;
        if(str == "end") break;
        if(validcheck(str)){
            cout << '<' << str << '>' << " is acceptable.\n";
        } else {
            cout << '<' << str << '>' << " is not acceptable.\n";
        }
    }
    return 0;
}
