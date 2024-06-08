#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n;
priority_queue<double, vector<double>, greater<double> > pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        double a;
        cin >> a;
        pq.push(a);
    }

    int cnt = 0;
    while(cnt++ < 7){
        cout.precision(3);
        cout << fixed << pq.top() << '\n';
        pq.pop();
    }
    return 0;
}
