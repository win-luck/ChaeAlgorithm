#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
long long n;
map<string, long long> m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    string s = "abcdefghi";
    long long cnt = 1;
    
    do{
        m[s] = cnt++;
    } while(next_permutation(s.begin(), s.end()));

    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        cout << m[str] << '\n';
    }
    return 0;
}