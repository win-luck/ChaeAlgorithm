#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    long zero = 0;
    long one = 0;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '0'){
            zero++;
            while(s[i] == '0'){
                i++;
            }
            i--;
        }
        else{
            one++;
            while(s[i] == '1'){
                i++;
            }
            i--;
        }
    }
    cout << min(zero, one) << '\n';
    return 0;
}