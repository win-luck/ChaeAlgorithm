#include <iostream>
#include <vector>
#include <set>

using namespace std;
int n;
vector<int> v;
bool visited[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    long long answer = 0;
    int l = 0;
    int r = 0;
    while(l < n){
        while(r < n){
            if(visited[v[r]]) break;
            visited[v[r]] = true;
            r++;
        }

        answer += (r-l);
        visited[v[l]] = false;
        l++;
    }

    cout << answer;
    return 0;
}
