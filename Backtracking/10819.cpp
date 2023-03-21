#include <iostream>
#include <vector>

using namespace std;
int n;
int arr[9];
bool visited[9];
vector<int> v;
int result = -1001;

void makeSum(){
    int sum = 0;
    for(int i=1; i<n; i++){
        sum += abs(v[i] - v[i-1]);
    }
    result = max(result, sum);
}

void DFS(int depth){
    if(depth == n){ // n개 수열 만들었다면 계산 돌입
        makeSum();
        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(arr[i]); // 순서가 다른 원소 n개 수열을 만드는 과정
        DFS(depth + 1);
        v.pop_back();
        visited[i] = false;
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    DFS(0);
    cout << result;
    return 0;
}