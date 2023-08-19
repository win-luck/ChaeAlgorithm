#include <iostream>
#include <vector>
#include <map>

using namespace std;
int n, P, F, S, V;
bool visited[16];
int ans = 987654321;
struct food { // 식재료 구조체
    int p;
    int f;
    int s;
    int v;
    int cost;
};
food foods[16];
vector<int> vec, anslist;

bool validcheck(int p, int f, int s, int v){
    if(p >= P && f >= F && s >= S && v >= V) return true;
    return false;
}

void DFS(int p, int f, int s, int v, int sum, int i){
    if(i == n){
        if(validcheck(p, f, s, v)){
            if(ans > sum){
                ans = sum;
                anslist = vec;
            } else if(ans == sum && anslist > vec){
                ans = sum;
                anslist = vec;
            }
        }
        return;
    }
    DFS(p, f, s, v, sum, i+1);
    vec.push_back(i);
    DFS(p+foods[i].p, f+foods[i].f, s+foods[i].s, v+foods[i].v, sum + foods[i].cost, i+1);
    vec.pop_back();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> P >> F >> S >> V;
    for(int i=0; i<n; i++){
        cin >> foods[i].p >> foods[i].f >> foods[i].s >> foods[i].v >> foods[i].cost;
    }
 
    DFS(0, 0, 0, 0, 0, 0);
    if(ans == 987654321) cout << -1 << '\n';
    else {
        cout << ans << '\n';
        for(int i=0; i<anslist.size(); i++){
            cout << anslist[i]+1 << " ";
        }
    }
    return 0;
}
