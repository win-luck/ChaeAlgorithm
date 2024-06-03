#include <iostream>
#include <vector>

using namespace std;
int arr[501];
int n;

void merge(vector<int>& array, int left, int mid, int right) {
    vector<int> L(array.begin() + left, array.begin() + mid + 1);
    vector<int> R(array.begin() + mid + 1, array.begin() + right + 1);

    int i = 0, j = 0;
    int k = left;
    int ll = L.size();
    int rl = R.size();

    while (i < ll && j < rl) {
        if (L[i] <= R[j]) {
            array[k] = L[i++];
        } else {
            array[k] = R[j++];
        }
        k++;
    }

    while (i < ll) {
        array[k++] = L[i++];
    }

    while (j < rl) {
        array[k++] = R[j++];
    }
}

void mergeSort(vector<int>& array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void solve() {
    vector<int> array = {230, 10, 60, 550, 40, 220, 20};
    mergeSort(array, 0, array.size() - 1);
}
