#include <iostream>
#include <algorithm>

using namespace std;
int n;
string str1, str2;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str1 >> str2;
        string tmp1 = str1;
        string tmp2 = str2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if(str1 == str2){
            cout << tmp1 << " & " << tmp2 << " are anagrams." << '\n';
        } else {
            cout << tmp1 << " & " << tmp2 << " are NOT anagrams." << '\n';
        }
    }
}