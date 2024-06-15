#include <iostream>
#include <queue>

using namespace std;
int n, h, t;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> h >> t;
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        pq.push(a);
    }
    int cnt = 0;
    while(t--){
        int top = pq.top();
        pq.pop();
        if(top != 1 && top >= h) {
            top /= 2;
            cnt++;
        }
        pq.push(top);
    }
    if(h > pq.top()){
        cout << "YES\n";
        cout << cnt;
    } else {
        cout << "NO\n";
        cout << pq.top();
    }
    return 0;
}
