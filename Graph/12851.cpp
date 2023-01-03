#include <iostream>
#include <queue>
#include <functional>

using namespace std;
int n, m;
const int MAX = 100001;
int visited[MAX];
int result = 0;
int mincount = 0;

void BFS(int n, int m){
    queue<pair<int, int> > q;
    q.push(make_pair(n, 0));

    while(!q.empty()){
        int num = q.front().first;
        int time = q.front().second;
        q.pop();
        visited[num] = 1; // pop할 때 visited 처리한다. 만약 아래에서 push할 때 시도하면 같은 숫자에서 시도하는 다른 모든 경우가 무시된다.

        if(result == 0 && num == m){
            result = time;
            mincount++;
            continue;
        }

        if(result != 0 && result == time && num == m){
            mincount++;
            continue;
        }

        if(num - 1 >=0 && !visited[num-1]){
            q.push(make_pair(num - 1, time + 1));
        }
        if(num + 1 <= m && !visited[num+1]){
            q.push(make_pair(num + 1, time + 1));
        }
        if(num * 2 <= m+1 && !visited[num*2]){
            q.push(make_pair(num * 2, time + 1));
        }
    }
}

int main(void) 
{
    cin >> n >> m;
    BFS(n, m);
    cout << result << endl;
    cout << mincount;

    return 0;
}
