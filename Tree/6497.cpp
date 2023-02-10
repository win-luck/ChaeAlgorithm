#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
bool exitflag;
long long totalsum;
int parent[200002];

int Find(int num){
    if(num == parent[num])
        return num;
    return parent[num] = Find(parent[num]);
}

bool Union(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x == y) return false;
    else {
        parent[x] = y;
        return true;
    }
}

int main(){
    int a, b;

    while(!exitflag){
        vector<pair<long long, pair<int, int> > > dist;
        cin >> m >> n;
        if(m == 0 && n == 0) break;

        for(int i=0; i<=m; i++){
            parent[i] = i;
        }
        
        for(int i=0; i<n; i++){
            long long c;
            cin >> a >> b >> c;
            
            dist.push_back(make_pair(c, make_pair(a, b)));
            dist.push_back(make_pair(c, make_pair(b, a)));
            totalsum += c;
        }

        sort(dist.begin(), dist.end());

        for(int i=0; i < dist.size(); i++){
            int a = Find(dist[i].second.first);
            int b = Find(dist[i].second.second);

            if(Union(a, b)){
                totalsum -= dist[i].first;
            }
        }

        cout << totalsum << endl;
        totalsum = 0;
    }

    return 0;
}