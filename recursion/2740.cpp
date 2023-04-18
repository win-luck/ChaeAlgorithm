#include <iostream>

using namespace std;
int n, m, k;
int a, b;
int arr1[101][101];
int arr2[101][101];
int answer[101][101] = {0,};

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){ // n * m 행렬 1
        for(int j=0; j<m; j++){
            cin >> a;
            arr1[i][j] = a;
        }
    }
    cin >> m >> k;
    for(int i=0; i<m; i++){ // m * k 행렬 2
        for(int j=0; j<k; j++){
            cin >> a;
            arr2[i][j] = a;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            for(int a=0; a<m; a++){ // 행렬의 곱셈
                answer[i][j] += arr1[i][a] * arr2[a][j];
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cout << answer[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}