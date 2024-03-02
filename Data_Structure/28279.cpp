#include <iostream>
#include <deque>

using namespace std;
int n, a, b;
deque<int> dq;
int s = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        if(a == 1){
            cin >> b;
            dq.push_front(b);
            s++;
        } else if(a == 2){
            cin >> b;
            dq.push_back(b);
            s++;
        } else if(a == 3){
            if(s > 0) {
                cout << dq.front() << '\n';
                dq.pop_front();
                s--;
            }
            else cout << -1 << '\n';
        } else if(a == 4){
            if(s > 0) {
                cout << dq.back() << '\n';
                dq.pop_back();
                s--;
            }
            else cout << -1 << '\n';
        } else if(a == 5){
            cout << s << '\n';
        } else if(a == 6){
            cout << (s == 0 ? 1 : 0) << '\n';
        } else if(a == 7){
            if(s > 0) {
                cout << dq.front() << '\n';
            }
            else cout << -1 << '\n';
        } else {
            if(s > 0) {
                cout << dq.back() << '\n';
            }
            else cout << -1 << '\n';
        }
    }
    return 0;
}
