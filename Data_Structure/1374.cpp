#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, a, b, c;
int answer = 0;
vector<pair<int, int> > v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c;
        v.push_back(make_pair(b, 1));
        v.push_back(make_pair(c, -1));
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i].second == 1){
            cnt++;
        } else {
            answer = max(answer, cnt);
            cnt--;
        }
    }
    cout << answer;
    return 0;
}
