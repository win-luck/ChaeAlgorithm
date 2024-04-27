#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int answer = 0;
vector<int> v;

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
    for(int i=0; i<n; i++){
        int cnt = 1;
        for(int j=i+1; j<i+5; j++){
            if(v[i] < v[j] && v[j] < v[i]+5) cnt++;
        }
        answer = max(answer, cnt);
    }
    if(answer >= 5) cout << 0;
    else cout << 5 - answer;
    return 0;
}
