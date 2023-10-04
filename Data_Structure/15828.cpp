#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a;
    queue<int> q;

    cin >> n;
    while(1){
        cin >> a;
        if(a == -1) break;
        else if(a == 0){
            q.pop();
        } else {
            if(q.size() >= n){
                continue;
            }
            q.push(a);
        }
    }
    if(q.empty()) cout << "empty" << '\n';
    else {
        while(!q.empty()){
            cout << q.front() << " ";
            q.pop();
        }
    }
    return 0;
}
