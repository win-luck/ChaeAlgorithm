#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int idx = 0;
int s = 0;
bool flag = false;
bool visited[10];

bool check(string s){ // 줄어드는 수
    for(int i=0; i<s.size()-1; i++){
        if(s[i] <= s[i+1]){
            return false;
        }
    }
    return true;
}

void dfs(int cnt, int now, string s){
    if(flag) return;
    if(now == cnt){
        if(check(s)){
            idx++;
            if(idx == n){
                flag = true;
                cout << s;
            }
        }
        return;
    }

    for(char i='0'; i<='9'; i++){
        if(!visited[i - '0'] && (s.empty() || s.back() > i)){
            visited[i - '0'] = true;
            dfs(cnt, now+1, s + (i));
            visited[i - '0'] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while(!flag){
        if(s >= 11) { // 자릿수 11부턴 불가능함 (9876543210)
            cout << -1;
            return 0;
        }
        dfs(++s, 0, "");
    }
    return 0;
}
