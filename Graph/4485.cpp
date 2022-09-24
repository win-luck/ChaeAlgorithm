#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
int arr[1001][1001];
int visited[1001][1001];
int x[4] = {-1, 0, 1, 0};
int y[4] = {0, 1, 0, -1};
int n;

int main(void)
{
    cin >> n;
    int arr[n+1][n+1];
    int dp[n+1][n+1];
    bool visited[n+1][n+1];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> arr[i][j];
        }
    }

    queue<pair<int, int>> q;
    visited[1][1] = true;
    q.push(make_pair(1, 1));

    while(q.size()!=0) {
			int px = q.front().first;
            int py = q.front().second;
            q.pop();

            for(int i=0; i<4; i++)
            {
                int p2x = px + x[i];
                int p2y = py + y[i];  
                if(p2x < 1 || p2y < 1 || p2x > n || p2y > m)
                    continue;
                if(visited[p2x][p2y] != 1)
                {
                    visited[p2x][p2y] = 1;
                    arr[p2x][p2y] = arr[px][py] + 1;
                    q.push(make_pair(p2x,p2y));
                }              
			}
		}
}