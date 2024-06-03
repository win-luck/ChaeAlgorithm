#include <iostream>
#include <vector>

using namespace std;
int arr[501];
int n;

int partition(vector<int>& array, int left, int right) {
    int mid = (left + right) / 2;
    swap(array[left], arr[mid]);

    int pivot = array[left];
    int i = left, j = right;

    while (i < j) {
        while (pivot < array[j]) {
            j--;
        }

        while (i < j && pivot >= array[i]) {
            i++;
        }
        swap(array[i], array[j]);
    }
    array[left] = array[i];
    array[i] = pivot;
    return i;
}

void quicksort(vector<int>& array, int left, int right) {
    if (left >= right) {
        return;
    }

    int pi = partition(array, left, right);
    quicksort(array, left, pi - 1);
    quicksort(array, pi + 1, right);
}

void solve() {
    vector<int> array = {80, 70, 60, 50, 40, 30, 20};
    quicksort(array, 0, array.size() - 1);
}
