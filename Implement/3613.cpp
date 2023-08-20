#include <iostream>
#include <string>

using namespace std;

bool isError(string str){
    bool upper = false; // 대문자
    bool underbar = false; // 언더바

    for(int i=0; i<str.size(); i++){
        if(str[i] == '_') underbar = true;
        else if(isupper(str[i])) upper = true;
    }

    if(underbar && upper) return true; // 둘다 동시에 존재하면 안 됨
    else if(str[0] == '_' || isupper(str[0])) return true; // 첫글자는 대문자나 언더바면 안 됨
    else if(str.back() == '_') return true; // 마지막 글자는 _면 안 됨

    for(int i=0; i<str.size()-1; i++){
        if(str[i] == '_' && str[i+1] == '_') return true; // 연속 _는 안 됨
    }

    return false;
}

bool isCpp(string str){ // C++은 _를 갖는다.
    for(int i=0; i<str.size(); i++){
        if(str[i] == '_') return true;
    }
    return false;
}

bool isJava(string str){ // 자바는 대문자를 갖는다.
    for(int i=0; i<str.size(); i++){
        if(isupper(str[i])) return true;
    }
    return false;
}

string CtoJava(string str){ // C++을 Java로
    string tmp = "";
    bool flag = false;

    for(int i=0; i<str.size(); i++){
        if(str[i] == '_') flag = true;
        else {
            if(flag){
                tmp += toupper(str[i]);
                flag = false;
            } else {
                tmp += str[i];
            }
        }
    }
    return tmp;
}

string JavatoC(string str){ // Java를 C++로
    string tmp = "";
    for(int i=0; i<str.size(); i++){
        if(isupper(str[i])){
            tmp += '_';
            tmp += tolower(str[i]);
        } else {
            tmp += str[i];
        }
    }
    return tmp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    if(isError(str)){
        cout << "Error!";
    } else if(isJava(str)){
        cout << JavatoC(str);
    } else if(isCpp(str)){
        cout << CtoJava(str);
    } else {
        cout << str;
    }
    return 0;
}