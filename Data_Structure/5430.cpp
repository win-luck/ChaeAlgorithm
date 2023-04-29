#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int T, n;
string p;
string str;

int main(){
    cin >> T;
    for(int i=0; i<T; i++){
        deque<int> q;
        bool isReverse = false;
        bool isError = false;

        cin >> p;
        cin >> n;
        cin >> str;
        string s = "";
        for(int i=0; i<str.length(); i++){ // 입력 문자 파싱 과정
            if(isdigit(str[i])){ // s는 단순 숫자만을 담다가
                s += str[i];
            } else { // ,나 ]을 만날 경우 파싱한다.
                if(!s.empty()){ // [를 막기 위한 조건문
                    q.push_back(stoi(s));
                    s = "";
                }
            }
        }

        for(int i=0; i<p.size(); i++){
            if(p[i] == 'R'){
                isReverse = !isReverse; // 실제로 뒤집진 않고 표시만 해 준다.
            } 
            if(p[i] == 'D'){
                if(q.empty()){ // 비어있으면 버릴 수 없다.
                    cout << "error" << '\n';
                    isError = true;
                    break;
                }
                if(isReverse) q.pop_back(); // 뒤집어져있다고 표시되면 뒤부터 날리면 된다.
                else q.pop_front();
            }
        }

        if(isError) continue; // 비어있으면 출력하지 않는다.
        cout << "[";
        while(!q.empty()){
            if(isReverse) { // 역행이면 뒤부터 출력하면 된다.
                cout << q.back();
                q.pop_back();
            }
            else { // 순행이면 앞부터 출력하면 된다.
                cout << q.front();
                q.pop_front();
            }
            if(!q.empty()) cout << ",";
        }
        cout << "]\n";
    }
    return 0;
}