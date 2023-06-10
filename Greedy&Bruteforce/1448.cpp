#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[1000001]; // nC3 절대 불가능

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>()); // 내림차순
    for(int i=0; i<=n-3; i++){ // 최댓값을 찾기 위해 붙어있는 3가지만 비교하면 됨
        if(arr[i] < arr[i+1] + arr[i+2]){
            cout << arr[i] + arr[i+1] + arr[i+2] << '\n';
            return 0;
        }
    }
    cout << -1;
    return 0;
}