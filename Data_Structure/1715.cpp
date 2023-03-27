#include <iostream>
#include <queue>

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int> > q;
    int n, val;
    int res = 0;

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> val;
        q.push(val);
    }

    while(q.size() > 1){ // 큐에 2개 이상 있을 때
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();

        res += (a + b); // 가장 작은 두 수의 합을 더한 후
        q.push(a + b); // 다시 큐에 넣음
    }
    cout << res;
    return 0;
}