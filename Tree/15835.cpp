#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct KS {int from, to, val;}; // 간선의 출발지, 도착지, 가중치
vector<KS> Edges;
int parent[21];
int n, m, t;

int find(int num){
    if(num == parent[num])
        return num;
    return parent[num] = find(parent[num]);
} // 유니온 파인드

bool cmp(KS k1, KS k2){
    return k1.val < k2.val;
}

int main(){
    cin >> t;
    for(int a=1; a<=t; a++){
        cin >> n >> m;
        Edges.clear();
        for(int i=1; i<=n; i++){
            parent[i] = i;
        }

        for(int i=0; i<m; i++){
            KS ks;
            cin >> ks.from >> ks.to >> ks.val;
            Edges.push_back(ks);
        }

        sort(Edges.begin(), Edges.end(), cmp);

        int result = 0;
        for(int i=0; i<Edges.size(); i++){
            int f = find(Edges[i].from);
            int t = find(Edges[i].to);

            if(f != t){
                parent[f] = t;
                result += Edges[i].val;
            }
        }
        cout << "Case #" << a << ": " << result << " meters" << '\n';
    }
    return 0;
}