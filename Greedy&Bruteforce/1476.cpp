#include <iostream>

using namespace std;
int e, s, m;
int re = 1, rs = 1, rm =1;
long long cnt = 1;

int main(){
    cin >> e >> s >> m;
    while(1){
        if(re == e && rs == s && rm == m) break;
        re++;
        rs++;
        rm++;
        cnt++;
        if(re > 15) re = 1;
        if(rs > 28) rs = 1;
        if(rm > 19) rm = 1;
    }
    cout << cnt << '\n';
}