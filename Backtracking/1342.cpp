#include <iostream>
#include <algorithm>

using namespace std;
string s;
long long answer = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    sort(s.begin(), s.end());
    do {
        bool flag = true;
        for(int i=0; i<s.size()-1; i++){
            if(s[i] == s[i+1]) {
                flag = false;
                break;
            }
       }
        if(flag) answer++;
    } while (next_permutation(s.begin(), s.end()));
    cout << answer;
    return 0;
}
