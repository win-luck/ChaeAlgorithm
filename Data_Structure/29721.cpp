#include <iostream>
#include <set>

using namespace std;
int n, k;
set<pair<int, int> > s;
set<pair<int, int> > origin;
int dx[4] = {2, -2, 0, 0};
int dy[4] = {0, 0, 2, -2};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<k; i++){
        int a, b;
        cin >> a >> b;
        origin.insert(make_pair(a, b));
    }
    for(auto it: origin){
        int a = it.first;
        int b = it.second;
        for(int j=0; j<4; j++){
            int nx = a + dx[j];
            int ny = b + dy[j];
            if(nx > 0 && ny > 0 && nx <= n && ny <= n){
                if(origin.find(make_pair(nx, ny)) == origin.end()){
                    s.insert(make_pair(nx, ny));
                }
            }
        }
    }
    cout << s.size();
    return 0;
}
