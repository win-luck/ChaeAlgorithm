#include <iostream>
#include <map>

using namespace std;
int n;
map<int, int> mx;
map<int, int> my;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int answer = 0;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        mx[x]++;
        my[y]++;
    }
    for(auto it: mx){
        if(it.second >= 2) answer++;
    }
    for(auto it: my){
        if(it.second >= 2) answer++;
    }
    cout << answer;
    return 0;
}
