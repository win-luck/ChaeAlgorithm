#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1, str2;
    int idx = 1;
    while(1){
        cin >> str1 >> str2;
        if(str1 == "END" && str2 == "END") break;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        cout << "Case " << idx++ << ": ";
        if(str1 == str2) cout << "same\n";
        else cout << "different\n";
    }
    return 0;
}
