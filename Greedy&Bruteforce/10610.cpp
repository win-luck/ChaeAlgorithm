#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    sort(str.begin(), str.end());
    reverse(str.begin(), str.end());
    if(str.back() != '0'){
        cout << -1;
    } else {
        int num = 0;
        for(int i=0; i<str.size(); i++){
            num += (str[i] - '0');
        }
        if(num % 3 == 0){
            cout << str;
        } else {
            cout << -1;
        }
    }
    return 0;
}
