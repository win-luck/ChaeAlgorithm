#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long sum = 0;
    int n, m;
    priority_queue<long long, vector<long long>, greater<long long> > q;

    cin >> n >> m;
    while(n--){
        long long a;
        cin >> a;
        q.push(a);
    }
    while(m--){
        long long x = q.top();
        q.pop();
        long long y = q.top();
        q.pop();
        q.push(x+y);
        q.push(x+y);
    }
    while(!q.empty()){
        sum += q.top();
        q.pop();
    }
    cout << sum;
    return 0;
}
