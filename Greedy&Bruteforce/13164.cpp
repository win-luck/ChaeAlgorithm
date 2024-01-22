#include <iostream>
#include <algorithm>

using namespace std;
int n, k;
vector<long long> v;
vector<long long> cost;
long long answer = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++){
        long long a;
        cin >> a;
        v.push_back(a);
    }
    for(int i=0; i<n-1; i++){
        cost.push_back(v[i+1]-v[i]);
    }
    sort(cost.begin(), cost.end());

    while(k-- > 1) cost.pop_back();
    for(int i=0; i<cost.size(); i++){
        answer += cost[i];
    }
    cout << answer;
    return 0;
}
