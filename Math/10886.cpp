#include <iostream>

using namespace std;
int arr[2] = {0, 0};

int main(){
    int n, a;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        arr[a]++;
    }
    cout << (arr[0] > arr[1] ? "Junhee is not cute!\n" : "Junhee is cute!\n");
}
