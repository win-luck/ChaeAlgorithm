#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, c, m, result;
int d[201][201];
int parent[201];
vector<pair<int, pair<int, int> > > dist; 
vector<pair<int, int> > v;

int Find(int n){
    if(n == parent[n]) return n;
    return parent[n] = Find(parent[n]);
}

bool Union(int a, int b){
    a = Find(a);
    b = Find(b);

    if(a == b) return false;
    else {
        parent[a] = b;
        return true;
    }
}

int main(){
    result = 0;
    cin >> n;
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> d[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(d[i][j] < 0){// 이미 연결되어 있는 도로는 반드시 포함
                Union(i, j);
                result += abs(d[i][j]); // 절댓값
            } else if (d[i][j] > 0) {
                dist.push_back(make_pair(d[i][j], make_pair(i, j)));
            }
        }
    }

    sort(dist.begin(), dist.end());

    for(int i=0; i<dist.size(); i++){
        int a = dist[i].second.first;
        int b = dist[i].second.second;
        int val = dist[i].first;

        if(Union(a, b)){
            result += val;
            v.push_back(make_pair(a, b)); // 새로 추가되는 도로의 쌍 저장
        }
    }
    cout << result << " " << v.size() << '\n';
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }
    return 0;  
}