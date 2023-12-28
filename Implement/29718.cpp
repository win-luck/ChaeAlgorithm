#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, a;
int arr[2001];
long long answer = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill(arr, arr+2001, 0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int tmp;
            cin >> tmp;
            arr[j] += tmp; // 각 열의 합을 계산
        }
    }
    cin >> a; // window size가 a
    for(int i=0; i<=m-a; i++){
        long long sum = 0;
        for(int j=i; j<i+a; j++){
            sum += arr[j];
        }
        answer = max(answer, sum);
    }
    cout << answer << '\n';
    return 0;
}
