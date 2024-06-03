#include <iostream>

using namespace std;
int arr[501];
int n;

void insertionSort()
{
   for(int i=1; i<n; i++){
      int temp = arr[i];
      int prev = i - 1;
      while((prev >= 0) && (arr[prev] > temp)) {
         arr[prev+1] = arr[prev];
         prev--;
      }
      arr[prev+1] = temp;
   }
}

