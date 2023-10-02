#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, a;
    priority_queue<int> q;

    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a;
        q.push(a);
    }

    bool flag = false;
    for(int i=0; i<m; i++){
       cin >> a;
       if(q.top() >= a){
            int x = q.top() - a;
            q.pop();
            q.push(x);
       } else {
            flag = true;
            break;
       }
    }
    cout << (flag ? 0 : 1) << '\n';
    return 0;
}
