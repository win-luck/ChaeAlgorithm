#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int n;
char a;
map<char, int> m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        string s = to_string(i);
        for(int j=0; j<s.size(); j++){
            m[s[j]]++;
        }
    }
    cin >> a;
    cout << m[a];
    return 0;
}
