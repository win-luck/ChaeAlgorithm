#include <iostream>
#include <cstring>

using namespace std;
int temp[5][5]; // 임시 행렬
int arr[5][5]; // A행렬
int answer[5][5] = { 0, }; // 정답 행렬
int n;
long long b;

void print(){ // 행렬 출력
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << answer[i][j] << " ";
        }
        cout << '\n';
    }
}

void matrix_cross(int answer[5][5], int arr[5][5]){
    memset(temp, 0, sizeof(temp));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                temp[i][j] += answer[i][k] * arr[k][j];
            }
            temp[i][j] %= 1000;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            answer[i][j] = temp[i][j];
        }
    }
}

int main(){
    cin >> n >> b;

    for(int i=0; i<n; i++){
        answer[i][i] = 1; // 최초 정답행렬은 Identify Matrix여야만 행렬 A와 한 번 곱했을 때 A가 이식된다.
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    while(b){
        if(b % 2 == 1){
            matrix_cross(answer, arr); // 홀수인 경우 1번 더 곱해주어야 한다.
        } 
        b/=2;
        matrix_cross(arr, arr); // A가 점점 2배곱된다. 
    }
    print();
    return 0;
}