#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, now;
    priority_queue<int> pq;

    cin >> n;
    cin >> now;
    for(int i=0; i<n-1; i++){
        int a;
        cin >> a;
        pq.push(a);
    }

    int cnt = 0;
    while(!pq.empty()){
        int x = pq.top();
        if(now > x) break;
        pq.pop();
        pq.push(x-1);
        cnt++;
        now++;
    }
    cout << cnt;
    return 0;
}
