#include <iostream>
#include <map>

#define MOD 1234567891
using namespace std;
int n;
string str;
map<char, long long> m;

void init(){
    int idx = 1;
    for(char i='a'; i<='z'; i++){
        m[i] = idx++;
    }
}

long long power(int i){
    long long val = 1;
    while(i > 0){
        val *= 31;
        val %= MOD;
        i--;
    }
    return val;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    cin >> n;
    cin >> str;
    long long answer = 0;
    for(int i=0; i<n; i++){
        answer += m[str[i]] * power(i);
        answer %= MOD;
    }
    cout << answer % MOD;
    return 0;
}
