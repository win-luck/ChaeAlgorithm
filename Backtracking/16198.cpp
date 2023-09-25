#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> e(11);
int n;
int ans = 0;

void DFS(vector<int> v, int sum){
    if(v.size() == 3){
        sum += (v[0] * v[2]);
        ans = max(ans, sum);
    } else {
        vector<int> tmp = v;
        for(int i=1; i<v.size()-1; i++){
            int val = tmp[i];
            tmp.erase(tmp.begin() + i);
            DFS(tmp, sum + (tmp[i-1]*tmp[i]));
            tmp.insert(tmp.begin() + i, val);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> e[i];
    }
    DFS(e, 0);
    cout << ans << '\n';
    return 0;
}
