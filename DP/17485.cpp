#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int lefts = 0;
int mids = 1;
int rights = 2;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int arr[n+1][m+1];
    int dp[3][n+1][m+1];
    int answer = INT_MAX;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> arr[i][j];
            if(i == 1)
            {
                dp[lefts][1][j] = arr[1][j];
                dp[mids][1][j] = arr[1][j];
                dp[rights][1][j] = arr[1][j];
            } // 첫번째 행 초기화
        }
    } // 입력


    for(int i=1; i<=n; i++)
    {
        dp[lefts][i][1] = INT_MAX; // 첫번째 열은 왼쪽에서 들어올 수 없음
        dp[rights][i][m] = INT_MAX; // 마지막 열은 오른쪽에서 들어올 수 없음
    }

    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(j == 1) // 왼쪽 끝이면 가운데와 오른쪽에서만 들어올 수 있다
            {
            dp[mids][i][j] = min(dp[rights][i-1][j], dp[lefts][i-1][j]) + arr[i][j];
            dp[rights][i][j] = min(dp[lefts][i-1][j+1], dp[mids][i-1][j+1]) + arr[i][j]; 
            }
            else if(j == m) // 오른쪽 끝이면 가운데와 왼쪽에서만 들어올 수 있다
            {
            dp[lefts][i][j] = min(dp[rights][i-1][j-1], dp[mids][i-1][j-1]) + arr[i][j];
            dp[mids][i][j] = min(dp[rights][i-1][j], dp[lefts][i-1][j]) + arr[i][j];
            }
            else { // 나머지는 모든 방향 가능
            dp[lefts][i][j] = min(dp[rights][i-1][j-1], dp[mids][i-1][j-1]) + arr[i][j];
            dp[mids][i][j] = min(dp[rights][i-1][j], dp[lefts][i-1][j]) + arr[i][j];
            dp[rights][i][j] = min(dp[lefts][i-1][j+1], dp[mids][i-1][j+1]) + arr[i][j];                             
            }
        }
    }

    for(int i = 1; i<=m; i++){
        for(int j=0; j<=2; j++)
        {
            answer = min(answer, dp[j][n][i]); // 최솟값 도출
        }
    }
    cout << answer;
}

// 3차원 배열을 쓰는 아이디어를 떠올렸다면 바로 풀 수 있었던 문제.
// "이전과 같은 방향으로 움직일 수 없다"를 어떻게 구현할 지가 포인트, flag 등의 변수처리를 하려면 더더욱 꼬이는 문제였음.
// 3차원 배열을 사용하는 것은 어색할 수 있지만, 불가능하지는 않다는 것을 잊지 말 것.
// 방향이나 케이스를 따져야 할 때 다차원 배열을 떠올리는 습관을 들이는 것도 좋겠다.