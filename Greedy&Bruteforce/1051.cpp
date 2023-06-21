#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
string str;
int cnt = 0;
int arr[51][51] = { 0, };
int answer[51][51] = {0,};

bool validcheck(int r, int c){
    int tmp = 1; // 기본 넓이 1
    int a = arr[r][c];
    int range = min(n, m); // 가장 큰 정사각형은 둘 중 작은 값임

    for(int i=range-1; i>=1; i--){
        if(r+i >= n || c+i >= m) continue;
        if(arr[r][c+i] == a && arr[r+i][c] == a && arr[r+i][c+i] == a){ // 동일한 숫자가 정사각형을 형성하는지
            tmp = max(tmp, i+1);
            break; // 최대 정사각형 찾기이므로 이탈
        }
    }
    answer[r][c] = tmp;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<m; j++){
            arr[i][j] = str[j] - '0';
        }
    } // 입력

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(validcheck(i, j)){ // (i, j)에서 정사각형이 만들어진다면
                cnt = max(cnt, answer[i][j]); // 최댓값 갱신
            }
        }
    }
    cout << cnt*cnt << '\n';
    return 0;
}
