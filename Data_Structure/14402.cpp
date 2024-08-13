#include <iostream>
#include <map>

using namespace std;
map<string, int> m;
string str;
int n;
char a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int cnt = 0;
    for(int i=0; i<n; i++){
        cin >> str >> a;
        if(a == '+'){
            m[str]++;
        } else {
            if(m[str] == 0) cnt++; // 들어간 기록 X, 나온 기록 O
            else m[str]--;
        }
    }

    for(auto it: m){
        cnt += it.second; // 들어간 기록 O, 나온 기록 X
    }
    cout << cnt;
    return 0;
}
