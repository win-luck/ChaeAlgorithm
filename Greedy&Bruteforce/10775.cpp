#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int g, p;
int parent[100001];
int res = 0;

int find(int num){
    if(num == parent[num])
        return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> g >> p;
    for(int i=1; i<=g; i++){
        parent[i] = i;
    }

    while(p--){
        int tmp;
        cin >> tmp;
        if(find(tmp) == 0) break;
        else {
            res++;
            merge(find(tmp), find(tmp) - 1);
        }
    }
    cout << res;
    return 0;
}