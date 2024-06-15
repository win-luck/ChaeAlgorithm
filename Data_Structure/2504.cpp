#include <iostream>
#include <stack>

using namespace std;
string str;
stack<char> oper;
stack<int> operand;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
    int temp = 1;
    int result = 0;
    bool flag = false;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(' || str[i] == '['){
            temp *= (str[i] == '(' ? 2 : 3);
            oper.push(str[i]);
        } else if(str[i] == ')'){
            if(oper.empty() || oper.top() != '('){
                flag = true;
                break;
            }
            if(str[i-1] == '('){
                result += temp;
            }
            temp /= 2;
            oper.pop();
        } else if(str[i] == ']'){
            if(oper.empty() || oper.top() != '['){
                flag = true;
                break;
            }
            if(str[i-1] == '['){
                result += temp;
            }
            temp /= 3;
            oper.pop();
        }
    }
    if(flag || !oper.empty()){
        cout << 0;
    } else {
        cout << result;
    }
    return 0;
}
