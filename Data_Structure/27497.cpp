#include <iostream>
#include <deque>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    stack<pair<char, int> > s;
    deque<char> dq;
    int n;

    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        char c;
        cin >> a;
        if(a == 1){
            cin >> c;
            dq.push_back(c);
            s.push(make_pair(c, 1));
        } else if(a == 2){
            cin >> c;
            dq.push_front(c);
            s.push(make_pair(c, 2));
        } else {
            if(s.empty() || dq.empty()) continue;
            pair<char, int> x = s.top();
            s.pop();
            if(x.first == dq.front() && x.second == 2){
                dq.pop_front();
            } else if(x.first == dq.back() && x.second == 1){
                dq.pop_back();
            }
        }
    }

    if(dq.empty()) {
        cout << 0;
        return 0;
    }
    string answer = "";
    while(!dq.empty()){
        answer.push_back(dq.front());
        dq.pop_front();
    }
    cout << answer << '\n';
    return 0;
}
