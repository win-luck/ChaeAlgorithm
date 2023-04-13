#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
int arr[9];
bool visited[9];
vector<int> v;

void backtracking(int cnt){
    if(cnt == m){
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=0; i<n; i++){ // 같은 수를 여러번 골라도 된다.
        visited[i] = true;
        v.push_back(arr[i]);
        backtracking(cnt + 1);
        v.pop_back();
        visited[i] = false;
    }
    
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n);
    backtracking(0);
}