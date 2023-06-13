#include <iostream>
#include <algorithm>

using namespace std;
int arr[9];
int arr2[9];
bool visited[9];

bool validcheck(int a){
    for(int i=1; i<=5; i++){
        if(a == arr2[i]) return true;
    }
    return false;
}

int main(){
    for(int i=1; i<=8; i++){
        cin >> arr[i];
        arr2[i] = arr[i];
    }

    sort(arr2 + 1, arr2 + 9, greater<int>());
    int sum = 0;
    for(int i=1; i<=8; i++){
        if(validcheck(arr[i])) {
            sum += arr[i];
            visited[i] = true;
        }
    }
    cout << sum << '\n';
    for(int i=1; i<=8; i++){
        if(visited[i]) cout << i << " ";
    }
    return 0;
}