#include <iostream>

#define INF 100
using namespace std;
int n;
string str;
char map[51][51] = { 0, };
int arr[51][51];
int answer = 0;

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> str;
        for(int j=1; j<=n; j++){
            map[i][j] = str[j-1];
            if(map[i][j] == 'Y'){
                arr[i][j] = 1;
            } else {
                arr[i][j] = INF;
            }
        }
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j || j == k || i == k) continue;
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        int temp = 0;
        for(int j=1; j<=n; j++){
            if(arr[i][j] <= 2){
                temp++;
            }
        }
        answer = max(answer, temp);
    }
    cout << answer << '\n';
    return 0;
}