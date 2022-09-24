#include <iostream>
#include <queue>

using namespace std;

int arr[1000][1000];
bool visited[1000][1000];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;

void BFS(int startx, int starty) {
		queue<pair<int, int>> q;

		q.push(make_pair(startx, starty));

		while(!q.empty()) {
			int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0 <= nx && nx < N && 0 <= ny && ny < M)
                {
                    if(visited[nx][ny] == false)
                    {
                        visited[nx][ny] = true;
                        arr[nx][ny] = arr[x][y] + 1;
                        q.push(make_pair(nx,ny));
                    }      
                }
			}
		}
	}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int targetx, targety;

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                arr[i][j] = 0;
                targetx = i;
                targety = j;
                visited[i][j] = true;
            }
            else if(arr[i][j] == 0)
            {
                visited[i][j] = true;
            }
        }
    }
    
    BFS(targetx, targety);

    for(int i=0; i < N; i++)
    {
        for(int j=0; j < M; j++)
        {
            if(visited[i][j] == false)
            {
                cout << "-1 ";
            }
            else
            {
                cout << arr[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
