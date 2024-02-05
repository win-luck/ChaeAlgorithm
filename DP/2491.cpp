#include <iostream>
#include <algorithm>

using namespace std;
int arr[100001];
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    int cnt = 1;
    int maxval1 = 0;
    for(int i=1; i<n; i++){
        if(arr[i] <= arr[i+1]){
            cnt++;
        } else {
            maxval1 = max(maxval1, cnt);
            cnt = 1;
        }
    }
    maxval1 = max(maxval1, cnt);

    int maxval2 = 0;
    cnt = 1;
    for(int i=1; i<n; i++){
        if(arr[i] >= arr[i+1]){
            cnt++;
        } else {
            maxval2 = max(maxval2, cnt);
            cnt = 1;
        }
    }
    maxval2 = max(maxval2, cnt);

    cout << max(maxval1, maxval2);
    return 0;
}
