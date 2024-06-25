#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
map<string, int> m1;
map<string, int> m2;
int n;
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        m1[s]++;
    }
    for(int i=0; i<n; i++){
        cin >> s;
        m2[s]++;
    }

    int answer = 0;
    for(auto it: m1){
        answer += min(m1[it.first], m2[it.first]);
    }
    cout << answer;
    return 0;
}
