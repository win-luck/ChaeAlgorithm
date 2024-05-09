#include <iostream>
#include <queue>

using namespace std;
int n, k;
string str;
int arr[200001][2];
bool visited[200001][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<=200000; i++){
        arr[i][0] = 1;
        arr[i][1] = 1;
    }
    for(int i=0; i<2; i++){
        cin >> str;
        for(int j=0; j<n; j++){
            arr[j][i] = str[j] - '0';
        }
    }

    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, make_pair(0, 0)));
    visited[0][0] = 1;

    while(!q.empty()){
        int time = q.front().first;
        int x = q.front().second.first;
        int dir = q.front().second.second;
        q.pop();

        if(x >= n){
            cout << 1;
            return 0;
        }

        if(!visited[x+1][dir] && arr[x+1][dir] == 1){
            q.push(make_pair(time+1, make_pair(x+1, dir)));
            visited[x+1][dir] = 1;
        }
        if(x >= 1 && !visited[x-1][dir] && arr[x-1][dir] == 1 && x-1 > time){
            q.push(make_pair(time+1, make_pair(x-1, dir)));
            visited[x-1][dir] = 1;
        }
        if(!visited[x+k][!dir] && arr[x+k][!dir] == 1){
            q.push(make_pair(time+1, make_pair(x+k, !dir)));
            visited[x+k][!dir] = 1;
        }
    }
    cout << 0;
    return 0;
}
