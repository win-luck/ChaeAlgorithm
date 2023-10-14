#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
string str;
int n;

int main(){
    cin >> str;
    string now = "";
    for(int i=0; i<str.size(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            continue;
        }
        now += str[i];
    }

    string f;
    cin >> f;
    if(now.find(f) == string::npos){
        cout << 0;
    } else {
        cout << 1;
    }
    return 0;
}