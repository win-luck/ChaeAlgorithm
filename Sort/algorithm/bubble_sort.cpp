#include <iostream>

using namespace std;
int n, k;
int cnt = 0;
int arr[10001] = { 0,};

void bubble_sort(){
    for(int i=0; i<n; i++){
        for(int j=1; j<n-i; j++){
            if(arr[j-1] > arr[j]){
                swap(arr[j], arr[j-1]);
                cnt++;
                if(cnt == k){
                    cout << arr[j-1] << " " << arr[j];
                    return;
                }
            }
        }
    }
    cout << -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bubble_sort();
    return 0;
}
