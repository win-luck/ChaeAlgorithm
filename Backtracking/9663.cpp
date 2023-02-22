#include <iostream>

int arr[16];
int n, result;

using namespace std;

bool validcheck(int cnt){
    for(int i=0; i<cnt; i++){
        if(arr[i] == arr[cnt] || abs(i - cnt) == abs(arr[i] - arr[cnt])){
            return false;
        }
    }
    return true;
}

void DFS(int cnt){
    if(cnt == n){
        result++;
        return;
    } else {
        for(int i=0; i<n; i++){
            arr[cnt] = i;
            if(validcheck(cnt)){
                DFS(cnt + 1);
            }
        }
    }
}

int main(){
    result = 0;
    cin >> n;
    DFS(0);
    cout << result << '\n';
    return 0;
}