#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;
int n;
string str;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        sort(str.begin(), str.end());
        do {
            cout << str << '\n';
        } while(next_permutation(str.begin(), str.end()));
    }

    return 0;
}