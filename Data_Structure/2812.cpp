#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
int n, k;
string str;
stack<char> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cin >> str;
    int cnt = 0;
    for(int i=0; i<str.size(); i++){
        while(!s.empty() && cnt < k && str[i] > s.top()){
            cnt++;
            s.pop();
        }
        s.push(str[i]);
    }

    while(cnt < k){ // 아직 몇 개 더 지워야 할 때
        s.pop();
        cnt++;
    }

    string answer = "";
    while(!s.empty()){
        answer += s.top();
        s.pop();
    }
    reverse(answer.begin(), answer.end());
    cout << answer << '\n';
    return 0;
}