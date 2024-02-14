#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
int n, m, a, b, sa, sb;
set<pair<int, int> > origin;
set<pair<int, int> > now;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m;
    cin >> sa >> sb;
    for(int i=1; i<m; i++){
        cin >> a >> b;
        origin.insert(make_pair(a-sa, b-sb));
    }

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a >> b;
        now.insert(make_pair(a, b));
    }

    for(auto it: now){
        int sx = it.first;
        int sy = it.second;
        bool flag = true;
        for(auto ori: origin){
            if(now.find(make_pair(sx+ori.first, sy+ori.second)) == now.end()){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << (sx-sa) << " " << (sy-sb);
            return 0;
        }
    }
    return 0;
}
