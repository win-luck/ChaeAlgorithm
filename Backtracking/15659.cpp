#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;
struct oper{
    string op;
    int priority;

    oper(string s, int p){
        op = s;
        priority = p;
    }
};
int n;
int arr[12];
int opcnt[4];
int mins = 1000000001;
int maxs = -1000000001;
map<int, string> m;
stack<int> num;
stack<oper> op;

void cal(){
    int res = 0;
    int b = num.top();
    num.pop();
    int a = num.top();
    num.pop();
    string o = op.top().op;
    op.pop();

    if(o == "+"){
        res = a + b;
    } else if(o == "-"){
        res = a - b;
    } else if(o == "*"){
        res = a * b;
    } else {
        res = a / b;
    }
    num.push(res);
}

int getres(string s){ // 사칙연산 by Stack
    stringstream ss(s);
    string tmp;
    while(ss >> tmp){
        int pr = 0;
        if(tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/"){
            if(tmp == "+" || tmp == "-"){
                pr = 1;
            } else {
                pr = 2;
            }

            while(!op.empty() && pr <= op.top().priority){
                cal();
            }
            op.push(oper(tmp, pr));
        } else {
            num.push(stoi(tmp));
        }
    }

    while(!op.empty()){
        cal();
    }
    return num.top();
}

void backtrack(int cnt, string s){
    if(cnt == n-1){ // 종료조건
        int sum = getres(s);
        maxs = max(maxs, sum);
        mins = min(mins, sum);
        while(!num.empty()){
            num.pop();
        }
        return;
    }

    for(int i=0; i<4; i++){
        if(opcnt[i] == 0) continue;
        
        opcnt[i]--;
        if(i == 0){
            backtrack(cnt + 1, s + " " + m[i] + " " + to_string(arr[cnt+1]));
        } else if(i == 1){
            backtrack(cnt + 1, s + " " + m[i] + " " + to_string(arr[cnt+1]));
        } else if(i == 2){
            backtrack(cnt + 1, s + " " + m[i] + " " + to_string(arr[cnt+1]));
        } else {
            backtrack(cnt + 1, s + " " + m[i] + " " + to_string(arr[cnt+1]));
        }
        opcnt[i]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<4; i++){
        cin >> opcnt[i];
    }
    m[0] = "+";
    m[1] = "-";
    m[2] = "*";
    m[3] = "/";

    backtrack(0, to_string(arr[0]));
    cout << maxs << '\n';
    cout << mins << '\n';
    return 0;
}
