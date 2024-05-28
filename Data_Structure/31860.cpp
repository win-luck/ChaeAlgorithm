#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    priority_queue<int> pq;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        pq.push(a);
    }

    vector<int> v;
    int before = 0;
    while(!pq.empty()){
        int now = pq.top();
        pq.pop();

        int satisfy = now + (before/2);
        v.push_back(satisfy);
        now -= m;
        if(now > k){
            pq.push(now);
        }
        before = satisfy;
    }

    cout << v.size() << '\n';
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }
    return 0;
}
