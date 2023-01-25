#include <iostream>
#include <algorithm>

using namespace std;
int n;
int matrix[501][501];
int dp[501][501];
int INF = 1000000000;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> matrix[i][0] >> matrix[i][1]; // 행과 열을 입력받아 저장
    }

    for (int i = 1; i < n; i++) { // 계산할 행렬 구간의 개수
        for (int j = 1; i + j <= n; j++) 
        { //
            dp[j][i + j] = INF; // 구간에 해당하는 행렬 먼저 최댓값으로 초기화

            for(int k = j; k <= i+j; k++){ // 순회할 구간을 나누는 k
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + matrix[j][0] * matrix[k][1] * matrix[i+j][1]);
            }
        }
    }

    // dp[1][3] = dp[1][1] + dp[2][3]이라 하면, 행렬1*행렬2 이후 행렬3을 곱할지, 행렬2*행렬3 이후 행렬1을 곱할지 선택지가 나뉜다.
    // 이는 첫번째 구간 시작점의 행 * 첫번째 구간 종점의 열 * 두번째구간 종점의 열로 일반화가 가능하다. 종점이 k인 것이다.
    // 예를 들어, dp[3][7]은 k=4일 때, dp[3][4] + dp[5][7]에서, matrix[3][0] * matrix[4][1] * matrix[7][1]로 구할 수 있다.

    cout << dp[1][n] << endl;
    return 0;
}