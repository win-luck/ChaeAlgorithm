#include <iostream>
#include <stack>

using namespace std;
stack<int> s;
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int now = 1;
    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a == now){
            now++;
        } else {
            s.push(a);
        }

        while(!s.empty() && s.top() == now){
            now++;
            s.pop();
        }
    }
    if(s.empty()) cout << "Nice";
    else cout << "Sad";
    return 0;
}
