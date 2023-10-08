#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    double a;
    priority_queue<double, vector<double>, greater<double> > q;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        q.push(a);
    }

    while(q.size() != 1){
        double x = q.top();
        q.pop();
        double y = q.top();
        q.pop();
        double next = (x + y) / 2;
        q.push(next);
    }

    cout << fixed;
    cout.precision(6);
    cout << q.top();
    return 0;
}
