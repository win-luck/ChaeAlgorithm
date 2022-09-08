#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            int x;
            cin >> x;
            arr[i] = x;
        }

        int maxnum = -1;
        long sum = 0;

        for(int i = n-1; i>=0; i--)
        {
            maxnum = max(maxnum, arr[i]);
            sum += (maxnum - arr[i]);            
        }
        cout << sum << "\n";
    }
}
