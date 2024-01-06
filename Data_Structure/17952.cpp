#include <iostream>
#include <stack>

using namespace std;
int n, a, b, c;
int sum = 0;
stack<pair<int, int> > s;

int main(){
    cin >> n;
    while(n--){
        cin >> a;
        if(a == 0){
            if(s.empty()) continue;
            pair<int, int> p = s.top();
            s.pop();
            if(p.second == 1){
                sum += p.first;
            } else {
                p.second--;
                s.push(p);
            }
            continue;
        } 
        cin >> b >> c;
        if(c == 1){ // 1초면 바로 끝난다.
            sum += b;
        } else {
            s.push(make_pair(b, c-1));
        }
    }
    cout << sum;
    return 0;
}
