#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;
map<string, string> m;
map<string, string> m2;
string s, answer1, answer2;
queue<long long> operands; // 숫자
queue<char> operators; // 연산자

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    
    m["ZERO"] = "0";
    m["ONE"] = "1";
    m["TWO"] = "2";
    m["THREE"] = "3";
    m["FOUR"] = "4";
    m["FIVE"] = "5";
    m["SIX"] = "6";
    m["SEVEN"] = "7";
    m["EIGHT"] = "8";
    m["NINE"] = "9";

    m2["0"] = "ZERO";
    m2["1"] = "ONE";
    m2["2"] = "TWO";
    m2["3"] = "THREE";
    m2["4"] = "FOUR";
    m2["5"] = "FIVE";
    m2["6"] = "SIX";
    m2["7"] = "SEVEN";
    m2["8"] = "EIGHT";
    m2["9"] = "NINE";

    for(auto it: m){
        size_t found = s.find(it.first);
        while(found != string::npos){
            s.replace(found, it.first.size(), it.second);
            found = s.find(it.first, found + 1);
        }
    }

    answer1 = s;
    string tmp = "";
    for(int i=0; i<s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){ // 숫자
            tmp += s[i];
        } else { // 연산자
            if(tmp == "+" || tmp == "-" || tmp == "x" || tmp == "/" || tmp == ""){
                cout << "Madness!" << '\n';
                return 0;
            }
            operands.push(stoll(tmp));
            tmp = "";
            operators.push(s[i]);
        }
    }

    if(operands.size() != operators.size()){
        cout << "Madness!" << '\n';
        return 0;
    }

    long long result = operands.front();
    operands.pop();
    while(!operands.empty()){
        char op = operators.front();
        operators.pop();
        long long x = operands.front();
        operands.pop();
        if(op == '+'){
            result += x;
        } else if(op == '-'){
            result -= x;
        } else if(op == 'x'){
            result *= x;
        } else if(op == '/'){
            result /= x;
        } else {
            break;
        }
    }

    answer2 = to_string(result); 
    for(auto it: m2){
        size_t found = answer2.find(it.first);
        while(found != string::npos){
            answer2.replace(found, it.first.size(), it.second);
            found = answer2.find(it.first, found + 1);
        }
    }
    cout << answer1 << '\n';
    cout << answer2 << '\n';
    return 0;
}
