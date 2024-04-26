#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n, 0);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int answer = 0;
    for(int i=0; i<n; i++){
        answer = max(answer, v[i] + i + 1);
    }
    cout << answer+1;
    return 0;
}
