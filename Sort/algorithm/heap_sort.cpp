#include <iostream>
#include <algorithm>

using namespace std;
int arr[501];
int n;

void heapify(int n, int i) {
    int p = i;
    int l = i*2 + 1;
    int r = i*2 + 2;
    
    //왼쪽 자식노드
    if (l < n && arr[p] < arr[l]) {
        p = l;
    }
    //오른쪽 자식노드
    if (r < n && arr[p] < arr[r]) {
        p = r;
    }
    
    //부모노드 < 자식노드
    if(i != p) {
        swap(arr[p], arr[i]);
        heapify(n, p);
    }
}

void heapSort() {
    // max heap 초기화
    for (int i = n/2-1; i>=0; i--){
        heapify(n, i); // 1
    }
    
    // extract 연산
    for (int i = n-1; i>0; i--) {
        swap(arr[0], arr[i]); 
        heapify(i, 0); // 2
    }
}
