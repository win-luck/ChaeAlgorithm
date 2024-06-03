#include <iostream>

using namespace std;
int n, k;
int cnt = 0;
int arr[10001] = { 0,};

void selection_sort(){
    for(int i=0; i<n-1; i++){
        int indexMin = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[indexMin]){
                indexMin = j;
            }
        }
        swap(arr[indexMin], arr[i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    selection_sort();
    return 0;
}
