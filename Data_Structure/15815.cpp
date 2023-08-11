#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
int ans = 0;

int main(){
    string str;
    cin >> str;

    stack<int> s;
    for(int i=0; i<str.size(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            s.push(str[i] - '0');
        } else {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if(str[i] == '+'){
                s.push(b + a);
            } else if(str[i] == '-'){
                s.push(b - a);
            } else if(str[i] == '*'){
                s.push(b * a);
            } else if(str[i] == '/'){
                s.push(b / a);
            }
        }
    }
    cout << s.top() << '\n';
    return 0;
}