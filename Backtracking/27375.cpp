#include <iostream>
#include <algorithm>
#include <vector>

struct lecture {
    int day, s, e;
    lecture(int a, int b, int c){
        day = a;
        s = b;
        e = c;
    }
};
using namespace std;
int n, k;
int answer = 0;
bool visited[21];
bool visited2[5][11];
vector<lecture> lecs;
vector<lecture> v;

bool isExist(lecture a){
    for(int j=a.s; j<=a.e; j++){
        if(visited2[a.day][j]){
            return true;
        }
    }
    return false;
}

void dfs(int idx, int grade){
    if(grade > k) return;
    if(grade == k){
        answer++;
        return;
    }

    for(int i=idx; i<n; i++){
        if(visited[i]) continue;
        lecture a = lecs[i];
        if(isExist(a)) continue;

        visited[i] = true;
        for(int j=a.s; j<=a.e; j++) visited2[a.day][j] = true;
        v.push_back(a);
        dfs(i, grade + a.e-a.s+1);
        v.pop_back();
        for(int j=a.s; j<=a.e; j++) visited2[a.day][j] = false;
        visited[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 5) continue;
        lecs.push_back(lecture(a, b, c));
    }
    n = lecs.size();

    dfs(0, 0);
    cout << answer;
    return 0;
}
