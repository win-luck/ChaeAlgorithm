#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
char c[4] = {'U', 'C', 'P', 'C'};

int main(){
    string str;
    getline(cin, str);

    int cnt = 0;
    for(int i=0; i<str.size(); i++){
        if(str[i] == c[cnt]){
            cnt++;
        }
    }
    if(cnt == 4){
        cout << "I love UCPC";
    } else {
        cout << "I hate UCPC";
    }
    return 0;
}