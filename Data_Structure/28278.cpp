#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    stack<int> s;

    cin >> n;
    for(int i=1; i<=n; i++){
        int a, b;
        cin >> a;
        if(a == 1){
            cin >> b;
            s.push(b);
        } else if(a == 2){
            if(!s.empty()){
                cout << s.top() << '\n';
                s.pop();
            } else {
                cout << -1 << '\n';
            }
        } else if(a == 3){
            cout << s.size() << '\n';
        } else if(a == 4){
            cout << (s.empty() ? 1 : 0) << '\n';
        } else {
            cout << (s.empty() ? -1 : s.top()) << '\n';
        }
    }
    return 0;
}
