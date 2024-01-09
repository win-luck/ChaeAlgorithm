#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, t;
double result = 0;
vector<int> v;
bool visited[8];
int totalcnt = 0;

void backtrack(int idx, int cnt){
    if(cnt == n){
        double tmp = 0;
        double tmpcnt = 0;
        for(int i=0; i<n; i++){
            if(visited[i]) {
                tmp += v[i];
                tmpcnt++;
            }
        }
        result += (tmp / tmpcnt);
        totalcnt++;
        return;
    }

    for(int i=idx; i<n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        backtrack(idx+1, cnt+1);
        visited[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for(int a=1; a<=t; a++){
        cin >> n;
        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            v.push_back(a);
        }

        backtrack(0, 0);
        cout << "#" << a << " ";
        cout << fixed;
        cout.precision(14);
        cout << result << '\n';
        
        result = 0;
        fill(visited, visited + 8, false);
        v.clear();
    }
    return 0;
}
